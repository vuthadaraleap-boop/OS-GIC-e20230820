# OS Lab 2 Submission — Linux Navigation & File Management

- **Student Name:** Vutha Daraleap
- **Student ID:** e20230820
- **Ubuntu username on the server:** gic-vutha-daraleap
- **My values** (`oslab values lab2`): file1 = vendor list.txt, file2 = travel claims.txt, owner = Finance, reader = Support, third = Marketing

---

## Core 1: Build the Company Folders

I created the department folders with one command:

```bash
mkdir -p "TechCorp/$owner/archive" "TechCorp/$reader" "TechCorp/$third"
```

`find TechCorp -type d` showed `TechCorp`, `TechCorp/Finance`, `TechCorp/Finance/archive`, `TechCorp/Support` and `TechCorp/Marketing`. The two reports in `incoming/` contain `amount,455` (`vendor list.txt`) and `amount,457` (`travel claims.txt`). I used the variables in double quotes because both file names have a space. Without quotes the shell splits `vendor list.txt` into two words, and `ls` reported that `incoming/vendor` and `list.txt` do not exist.

## Core 2: Move and Copy With My Own Paths

1. From inside `incoming/` I moved the first report with a **relative** destination: `mv -- "$file1" ../reports/`. `..` goes up one folder, and then `reports/` is next to `incoming/`.
2. From the lab folder I moved the second report with **absolute** paths for the source and the destination, both starting with `$OSLAB_WORKSPACE/lab2/`.
3. I copied both reports from `reports/` into `TechCorp/Finance/` with `cp`. The originals stayed in `reports/`.
4. I copied the first report into `TechCorp/Finance/archive/` with the new name `first-original.txt`.
5. From inside `TechCorp/Support/` I read the first report in `TechCorp/Finance/` with a relative path (`../Finance/vendor list.txt`) and with an absolute path. Both printed `amount,455`.

**My decision (step 3):** I used relative paths, because I was already in the lab folder and they are short. Absolute paths are better in a script, or when the folder I start from can change, because they mean the same place from anywhere. The commands are saved in `evidence/paths.txt`.

## Core 3: Prove It

- **Identical copies:** `cmp` printed nothing for both reports, so the copies in `TechCorp/Finance/` have exactly the same bytes as the files in `reports/`. A name in `ls` would not prove that.
- **Path error on purpose:** From `TechCorp/Support/` I ran `cat "reports/$file1"`. It failed with `No such file or directory`, although the file exists. A relative path starts from the folder I am in, and there is no `reports` folder inside `Support`.
- **Fix:** `../../reports/vendor list.txt`. The first `..` goes from `Support` to `TechCorp`, and the second goes to the lab folder, where `reports/` is.
- **Final list:** `find incoming reports TechCorp -type f | sort | tee evidence/tree.txt` saved the list of files. `incoming/` is empty, because `mv` moved both reports out.
- `oslab check lab2` showed `milestones: 5/5`.

## My Prediction: Confirmed or Corrected

(Fill in after `oslab debrief lab2`.)

- **Answer 1:** confirmed or corrected, and what I saw.
- **Answer 2:** confirmed or corrected, and what I saw.
- **Answer 3:** confirmed or corrected, and what I saw.
- **Answer 4:** confirmed or corrected, and what I saw.
- **Answer 5:** confirmed or corrected, and what I saw.

## Live Checkpoint

(Fill in after the checkpoint. The output is saved in `evidence/checkpoint.txt`.)

## Plus / Challenge (only if you did them)

Not done.

## AI Note (optional)

An AI tool gave me the commands for Core 2 and Core 3. I ran them myself, checked each result with `ls`, `find` and `cmp`, and read the error messages to see why they happened.
