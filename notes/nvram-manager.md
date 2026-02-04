# NVRAM Manager (Bare-Metal)

## Overview

NVRAM (Non-Volatile Random Access Memory) is used to store data that must
persist across power cycles. Typical use cases include configuration
parameters, calibration data, counters, and system state.

An NVRAM Manager provides a safe and structured way to access non-volatile
memory instead of directly reading or writing flash/EEPROM.

This document explains the design philosophy, responsibilities, and usage
of an NVRAM Manager in a bare-metal embedded system.

---

## Why an NVRAM Manager is Needed

Directly writing to flash or EEPROM can cause several issues:

- Limited erase/write cycles (flash wear-out)
- Data corruption during unexpected resets
- No validation of stored data
- Difficult firmware upgrades due to structure changes
- Hard-coded memory addresses scattered in code

An NVRAM Manager solves these problems by providing abstraction,
data integrity checks, and centralized control.

---

## Responsibilities of the NVRAM Manager

### 1. Data Abstraction
Access NVRAM using logical IDs instead of physical addresses.

### 2. Data Integrity
Ensure stored data is valid using:
- Magic numbers
- CRC or checksum
- Length and version checks

### 3. Wear Leveling (Basic)
Avoid repeatedly writing to the same flash page by rotating storage locations.

### 4. Versioning Support
Handle firmware updates safely by detecting structure version mismatches.

### 5. Centralized Memory Layout
Define all NVRAM regions and sizes in one location.

---

## Typical Architecture

