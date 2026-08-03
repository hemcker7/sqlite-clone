# Architecture (Version 0.1)

## High-Level Pipeline

```
User
 │
 ▼
Input Reader
 │
 ▼
Meta Command Handler
 │
 ▼
Parser
 │
 ▼
Statement
 │
 ▼
Executor
 │
 ▼
Table
 │
 ▼
Serialization
```

---

# Module Responsibilities

## Input Reader

Responsible for reading user input.

Owns:

* Current input buffer

Does NOT:

* Parse SQL
* Execute commands

---

## Meta Command Handler

Handles commands beginning with `.`

Examples:

* `.exit`

Does NOT:

* Parse SQL

---

## Parser

Converts raw SQL into a `Statement`.

Responsibilities:

* Identify statement type
* Validate syntax
* Construct domain objects (`Row` for INSERT)

Does NOT:

* Modify database state
* Print output

---

## Statement

Intermediate representation of a parsed SQL statement.

Current fields:

* StatementType
* Row (used by INSERT)

Future:

* Table name
* WHERE clause
* LIMIT
* ORDER BY

---

## Executor

Coordinates execution.

Responsibilities:

* Execute parsed statements
* Delegate storage operations to `Table`

Does NOT:

* Parse SQL
* Store data directly

---

## Table

Represents an in-memory table.

Responsibilities:

* Store rows
* Provide read-only access to stored rows

Does NOT:

* Understand SQL
* Print data

---

## Row

Represents a logical database record.

Current fields:

* id
* username
* email

This is an in-memory representation only.

---

## Serialization

Stateless utility module.

Responsibilities:

* Convert `Row` ↔ binary record

Owns:

* Knowledge of the binary record layout

Does NOT:

* Allocate memory
* Own memory
* Read/write files
* Manage pages

---

# Binary Record Layout

```
Offset      Size

0           4      ID
4           32     USERNAME
36          255    EMAIL

Total: 291 bytes
```

The binary format is intentionally independent of the in-memory C++ representation.

---

# Important Design Decisions

## Parser constructs domain objects

The parser creates a fully populated `Row` during INSERT parsing.

The executor does not parse or construct rows.

---

## Storage layer is SQL-independent

`Table` does not accept `Statement` objects.

It stores and retrieves rows only.

---

## Serialization is stateless

Serialization functions operate on caller-provided buffers.

Ownership of memory remains with the caller.

---

## Fixed-size records

Rows are serialized into a deterministic binary format with fixed offsets.

This simplifies:

* Page layout
* Offset calculations
* Future persistence

---

# Planned Next Layer

```
Table
 │
 ▼
Pager
 │
 ▼
4096-byte Pages
 │
 ▼
Disk
```

The pager will become the abstraction responsible for page allocation, caching, loading, and flushing.
