# OS Lab 2 — Linux Navigation & File Management

| | |
|---|---|
| **Student ID** | e20230820 |
| **Course** | Operating Systems |
| **Lab** | Mastering Linux Navigation & File Management |
| **Lab Type** | Individual |

## Overview

In this lab I played the role of Alex, a junior system administrator at TechCorp Inc. I navigated the Linux filesystem, built a multi-level directory structure for three departments (HR, Engineering, Marketing), organized files with `cp`, `mv` and `rm`, and audited the result with advanced `ls` options.

## Final Directory Structure

```
lab2/
├── README.md
├── task1_basic_navigation.txt
├── task2_filesystem_exploration.txt
├── task3_directory_structure.txt
├── task4_navigation_paths.txt
├── task5_file_organization.txt
├── task6_advanced_listing.txt
└── techcorp/
    ├── hr/
    │   ├── policies/       (leave_policy.txt, remote_work.txt)
    │   └── onboarding/     (checklist.txt, handbook.txt, leave_policy.txt, welcome_guide.txt)
    ├── engineering/
    │   ├── frontend/       (frontend_config.txt, index.html, styles.css)
    │   ├── backend/        (server_config.txt, pipeline_backup.txt, app.js, database.sql)
    │   └── devops/         (pipeline.txt, server_notice.txt, security_audit.txt, Dockerfile, docker-compose.yml)
    └── marketing/
        ├── campaigns/      (q1_2026_launch.txt, social_media.txt)
        └── assets/         (logo.png, banner.jpg, brochure.pdf, logo_brief.txt)
```

---

## Task 1 — Basic Navigation Warm-Up

**Commands used:** `pwd`, `ls`, `ls -la`, `cd`, `cd ~`

I printed my current location, listed my home directory (including hidden files), moved to the root directory `/`, and returned home with `cd ~`.

**Output file:** [task1_basic_navigation.txt](task1_basic_navigation.txt)

---

## Task 2 — Exploring the File System

**Commands used:** `cd` (absolute paths), `pwd`, `ls`, `ls -la`

I visited the key system directories and recorded their contents:

| Directory | Purpose |
|---|---|
| `/` | Root of the filesystem; every other path starts here |
| `/etc` | System-wide configuration files |
| `/var` | Variable data such as logs and caches |
| `/home` | Home directories of users |
| `/tmp` | Temporary files |

**Output file:** [task2_filesystem_exploration.txt](task2_filesystem_exploration.txt)

---

## Task 3 — Building the Company Directory Structure

**Commands used:** `mkdir -p`, `touch`, `echo`, `tree`

I created the whole tree in one command using brace expansion:

```bash
mkdir -p techcorp/{hr/{policies,onboarding},engineering/{frontend,backend,devops},marketing/{campaigns,assets}}
```

Then I filled the folders with placeholder files using `echo` (files with content) and `touch` (empty files), and saved the structure with `tree`.

**Output file:** [task3_directory_structure.txt](task3_directory_structure.txt)

---

## Task 4 — Navigating with Absolute and Relative Paths

**Commands used:** `cd` (absolute and relative), `..`, `.`, `cd -`, `pwd`

I moved between departments using absolute paths, relative paths, `..` for the parent directory, and `cd -` to return to the previous directory.

**Challenge commands:**

```bash
cd techcorp/engineering/backend                    # 8a: relative path
cd ../../marketing/assets                          # 8b: only .. shortcuts
cd /usr/bin                                        # 8c: absolute path
cd -                                               # 8d: back to previous directory
cd ~/os-gic-e20230820/os-lab-e20230820/lab2/techcorp/hr/onboarding   # 8e: any method
```

**Output file:** [task4_navigation_paths.txt](task4_navigation_paths.txt)

---

## Task 5 — Organizing Files Across Directories

**Commands used:** `cp`, `mv`, `rm`, `ls`, `tree`

I fixed misplaced files by moving, copying, renaming and removing them with relative paths:

- Moved `server_notice.txt` from marketing to `engineering/devops/`
- Moved `logo_brief.txt` from backend to `marketing/assets/`
- Removed `temp_debug.log` from `hr/policies/`
- Moved `handbook.txt` from devops to `hr/onboarding/`
- Copied `leave_policy.txt` to `hr/onboarding/`
- Renamed `q1_launch.txt` to `q1_2026_launch.txt`

**Challenge commands:**

```bash
# 9a: create in the wrong place, then move to the right one
echo "Annual Security Audit Report 2026" > techcorp/hr/policies/security_audit.txt
mv techcorp/hr/policies/security_audit.txt techcorp/engineering/devops/

# 9b: copy for backup
cp techcorp/engineering/devops/pipeline.txt techcorp/engineering/backend/pipeline_backup.txt

# 9c: create three junk files, remove them with one command
touch techcorp/marketing/campaigns/{draft1.tmp,draft2.tmp,old_notes.tmp}
rm techcorp/marketing/campaigns/*.tmp

# 9d: rename in the same directory
mv techcorp/engineering/frontend/app_config.txt techcorp/engineering/frontend/frontend_config.txt
```

**Output file:** [task5_file_organization.txt](task5_file_organization.txt)

---

## Task 6 — Advanced Listing & Directory Audit

**Commands used:** `ls -R`, `ls -lS`, `ls -lt`, `ls -lh`, `ls -rlS`, `ls -rlt`, `ls -lhRS`

| Flag | Meaning |
|---|---|
| `-R` | Recursive listing of all subdirectories |
| `-l` | Long format |
| `-S` | Sort by size, largest first |
| `-t` | Sort by modification time, newest first |
| `-h` | Human-readable sizes (K, M, G) |
| `-r` | Reverse the sort order |

**Challenge commands:**

```bash
ls -lt techcorp/hr/onboarding/            # 6a: newest modified first
ls -lhR techcorp/marketing/               # 6b: recursive, long, human-readable
ls -rlS techcorp/engineering/devops/      # 6c: smallest files first
ls -ldhS ~/.[!.]*                         # 6d: hidden files, largest first
```

**Output file:** [task6_advanced_listing.txt](task6_advanced_listing.txt)

---

## Conclusion

In this lab I practiced navigating the Linux filesystem with absolute and relative paths, built a nested directory structure with `mkdir -p`, organized files with `cp`, `mv` and `rm`, and used advanced `ls` options to list and sort directory contents. The main thing I learned is how much faster relative paths and `..` make moving around once I know where I am with `pwd`.
