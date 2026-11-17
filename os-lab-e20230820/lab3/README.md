# OS Lab 3 — Wildcards, Links, GRUB & Shared Libraries

- **Student Name:** Vutha Daraleap
- **Student ID:** e20230820
- **Date:** November 17, 2026

---

## Task 1 — Mastering Wildcards

Used `*`, `?`, `[...]`, `[!...]`, and `{...}` brace expansion to filter, copy, create, and remove groups of files inside `wildcard_lab/` and `csv_archive/`. Full output is recorded in `task1_wildcards.txt` and `evidence/wildcards.txt`.

![Task 1 Challenge](images/task1_challenge.png)

---

## Task 2 — Hard Links and Symbolic Links

Created and inspected hard links (`ln`) and symbolic links (`ln -s`) using `ls -li`, `stat`, and `readlink`. Full output is saved in `task2_links.txt` and `evidence/links.txt`.

![Task 2 Challenge](images/task2_challenge.png)

---

## Task 3 — GRUB: Exploration, Customization & Boot Recovery

Audited `/boot/grub/grub.cfg`, `/etc/default/grub`, `/etc/grub.d/`, kernel images (`vmlinuz`, `initrd`), and boot logs in `task3_grub.txt`.

![VM Snapshot](images/task3_snapshot.png)
![GRUB Timeout](images/task3_timeout.png)
![GRUB Custom Entry](images/task3_custom_entry.png)
![GRUB Background](images/task3_background.png)
![GRUB Recovery](images/task3_recovery.png)
![GRUB Break](images/task3_break.png)
![GRUB Manual Boot](images/task3_manual_boot.png)
![GRUB Restored](images/task3_restored.png)
![GRUB Challenge](images/task3_challenge.png)

---

## Task 4 — Shared Objects (Dynamic Libraries) Exploration

Inspected dynamic library dependencies and ELF headers using `ldd`, `ldconfig -p`, `file`, `readelf -h`, and `/proc/$$/maps`. Full output is recorded in `task4_shared_objects.txt`.

![Task 4 Challenge](images/task4_challenge.png)

---

## Task 5 — Build & Register a Shared Library (Pair Task)

Designed `techcorp_sysinfo.h`, compiled position-independent code (`-fPIC`) into `libtechcorp_sysinfo.so`, extended it with `tc_get_memory_mb()` in `techcorp_memory.c`, and linked `sysinfo_test` and `sysinfo_test_v2`. Full output is recorded in `task5_shared_library.txt`.

![Pair Design](images/task5_pair_design.png)
![Pair Integration](images/task5_pair_integration.png)

---

## Full Command History

![Full History](images/full_history.png)
