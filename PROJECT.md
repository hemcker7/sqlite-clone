# SQLite Clone in Modern C++

A from-scratch SQLite-inspired relational database written in modern C++ as a learning project to understand how real database engines work internally.

> **Goal:** Learn database internals by building each layer ourselves instead of relying on existing libraries.

---

## Current Status (Version 0.1)

### Completed

* Interactive REPL
* Input handling
* Meta commands (`.exit`)
* SQL statement parser
* Statement abstraction
* Executor
* In-memory table
* Row abstraction
* Binary row serialization
* Binary row deserialization
* Basic validation for SQL statements

Currently supported SQL:

```sql
insert <id> <username> <email>
select
```

Example:

```text
db > insert 1 Alice alice@example.com
Executed.

db > insert 2 Bob bob@example.com
Executed.

db > select

1 Alice alice@example.com
2 Bob bob@example.com
```

---

## Project Goals

This project is intentionally built layer by layer to understand how real databases work.

Planned implementation includes:

* Fixed-size record serialization
* Pager
* Disk persistence
* Page cache
* B-Tree
* Cursor
* Multiple pages
* CREATE TABLE
* Multiple tables
* Basic query planner
* Networking (database server mode)
* Transactions
* Recovery

---

## Current Architecture

```
Console
    │
Input Reader
    │
Meta Command Handler
    │
SQL Parser
    │
Statement
    │
Executor
    │
Table
    │
Row
    │
Serialization
```

---

## Design Philosophy

This project follows several guiding principles:

* Single Responsibility Principle
* Clear separation between parsing and execution
* Storage layer independent of SQL layer
* Stateless helper modules where appropriate
* Binary formats explicitly defined
* Incremental development with continuous refactoring

---

## Technologies

* C++20
* STL
* g++
* VS Code

Future:

* CMake
* GoogleTest

---

## Roadmap

### Version 0.2

* Pager
* Fixed-size pages
* Persistence

### Version 0.3

* B-Tree
* Cursor
* Searching

### Version 0.4

* Internal nodes
* Root splitting

### Version 0.5

* Multiple tables
* CREATE TABLE

### Version 0.6

* Database server
* TCP networking
* Client protocol

---

## Learning Objectives

The purpose of this project is not merely to build a working database but to understand the design decisions behind systems like SQLite, including:

* Binary serialization
* Memory management
* Page-based storage
* B-Tree indexing
* Query execution
* Storage engine architecture
* Systems programming in modern C++
