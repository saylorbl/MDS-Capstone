The goal of this README is to give everyone (regardless of previous Git/GitHub experience) a basic guide to working with this repository.

---

## 📁 Repository Structure

The repository will generally be organized like this:

```text
/
├── CAD/                  # CAD models, assemblies, drawings, etc.
│   ├── Parts/
│   ├── Assemblies/
│   └── Drawings/
│
├── Code/                 # Source code
│   ├── Firmware/
│   └── Software/
│
├── Documentation/        # Project documentation
│
├── Testing/              # Test plans, results, and data
│
└── README.md
```

---

# 🧠 Git vs. GitHub

### Git

Git is the version-control system that tracks changes to files on your computer.

### GitHub

GitHub is the website/service where our Git repository is hosted and shared with the team.

> **Git = the tool that tracks changes**
> **GitHub = the place where we share those changes**

---

# 🚀 Getting Started

## 1. Install Git

If you don't already have Git installed, download it from:

https://git-scm.com/

You can verify that Git is installed by opening a terminal and running:

```bash
git --version
```

---

## 2. Clone the Repository

**Cloning** downloads a copy of the repository onto your computer.

I would recommend using VScode, because it is really easy to clone, push, and pull.

1. In the Github, click the green "<> Code" button and copy the HTTPS link
2. Open VScode
3. You should see a button that says "Clone Repo". Press that, then paste the copied link.
4. Navigate to where you want the repo saved on your computer

You can clone from git bash or the cmd line too, but that's a bit more computer monkey

# 🔄 The Basic Git Workflow

Most of the time, your workflow will look like this:

```text
Pull
  ↓
Branch
  ↓
Create/modify files
  ↓
Check your changes
  ↓
Commit
  ↓
Push
  ↓
Pull Request
  ↓
Review
  ↓
Merge
```

The most important commands to know are:

```bash
git pull
git status
git add
git commit
git push
```

---

# ⬇️ Pulling Changes

Before beginning work, **always pull the latest version** of the repository.

```bash
git pull
```

This downloads changes that other teammates have pushed to GitHub and ensures
you are working from the most recent version.

---

# 🔎 Checking Your Changes

Use:

```bash
git status
```

This tells you what Git sees as changed.

For example:

```text
modified: Code/Firmware/motor_control.cpp
modified: CAD/Parts/cutting_arm.step
```

`git status` is one of the safest and most useful commands you can run.

**If you're ever unsure what is going on, run `git status`.**

---

# 🌿 Branches

A **branch** is a separate version of the project where you can work without immediately changing the main codebase.

## Don't work directly on `main`

The `main` branch should represent the stable version of the project.

Instead, create a branch for your work.

```bash
git checkout -b feature-name
```

A good branch name should tell someone **what you are working on**.

---

# 💾 Committing Changes

A **commit** is a saved checkpoint of your work.

First, check what changed:

```bash
git status
```

Then add the files you want to commit:

```bash
git add .
```

Then create the commit:

```bash
git commit -m "Add motor control logic"
```

A commit message should briefly explain **what you changed**.

---

# ⬆️ Pushing Changes

After committing your work, send your branch to GitHub:

```bash
git push
```

If this is the first time you're pushing a new branch, Git may ask you to use:

```bash
git push -u origin branch-name
```

After using that command for the first time, you should be able to push on that
branch normally.

---

# 🔀 Pull Requests

After pushing your branch to GitHub, you should generally create a **Pull Request (PR)**.

A Pull Request asks the team:

> "I've finished these changes. Can someone review them before we put them into `main`?"

### Do NOT automatically merge your own PR

Whenever practical, have another teammate review your work before merging it into `main`.

This helps catch:

- Bugs
- Design problems
- Conflicting changes
- Accidental file deletions
- Poor implementation decisions

---

# 🧹 After Your Pull Request Is Merged

Once your branch has been merged, switch back to `main`:

```bash
git checkout main
```

Then update it:

```bash
git pull
```

You can then delete your old local branch if you're finished with it:

```bash
git branch -d branch-name
```

---

# 🛠️ Example: Complete Workflow

Suppose you're responsible for the motor-control software.

### 1. Start with the latest project

```bash
git checkout main
git pull
```

### 2. Create a branch

```bash
git checkout -b motor-control
```

### 3. Make your changes

Edit the code normally.

### 4. Check your work

```bash
git status
```

### 5. Add your changes

```bash
git add .
```

### 6. Commit

```bash
git commit -m "Add motor control logic"
```

### 7. Push

```bash
git push -u origin motor-control
```

### 8. Create a Pull Request

Go to GitHub and create a PR from:

```text
motor-control → main
```

### 9. Get your code reviewed

A teammate reviews the changes.

### 10. Merge

Once approved, merge the PR into `main`.

---

# ⚠️ CAD File Guidelines

CAD files require a little more care than normal source-code files.

## Keep CAD organized

Use the appropriate folders:

```text
CAD/
├── Parts/
├── Assemblies/
└── Drawings/
```

## Use descriptive filenames.

# 📦 Large CAD Files

CAD files can become very large.

**Do not commit unnecessary large files** such as:

- Temporary exports
- Rendered videos
- Simulation caches
- Temporary files
- Build files
- Software-generated cache folders

If a file is extremely large, **talk to the team before adding it to the repository.**

We may need to use Git LFS (Large File Storage) or another storage solution.

---

# 🚫 What NOT to Commit

Do not commit:

### Passwords or secrets

```text
API keys
Passwords
Tokens
Private credentials
.env files containing secrets
```

### Temporary files

```text
*.tmp
*.bak
temporary exports
software caches
```

### Build/generated files

Don't commit generated files unless the team has specifically decided that they belong in the repository.

---

# 🔐 Never Put Secrets on GitHub

**Assume that anything pushed to GitHub can potentially be seen by others.**

## Never put passwords, API keys, private tokens, or other credentials directly into code.

# 💥 Merge Conflicts

Sometimes Git will report a **merge conflict**.

This usually happens when two people modify the same part of a file.

Git may show something like:

```text
<<<<<<< HEAD
your version
=======
their version
>>>>>>> other-branch
```

Don't panic.

A conflict means Git needs a human to decide which changes should remain.

### If you encounter a conflict:

**Don't randomly delete things until Git stops complaining.**

Instead:

1. Stop and inspect the conflict.
2. Determine what each version is trying to accomplish.
3. Resolve the conflict carefully.
4. Test the result.
5. Commit the resolution.

If you're unsure, **ask another teammate for help.**

Specifically, ask me (Bradley) because I have a tool on my computer that makes it
easier to track conflicts. But they are a huge pain, so try to avoid them.

---

# 🧯 "I Messed Something Up"

**Don't panic.**

Git is designed to let us recover from mistakes.

If you haven't committed or pushed your changes yet, **stop before running random Git commands**.

Ask a teammate for help.

A good rule is:

> **If you don't know what a Git command will do, don't run it just because someone told you to copy/paste it.**

Especially be careful with commands involving:

```bash
git reset
git clean
git push --force
```

These can potentially delete or overwrite work.

---

# 📋 Quick Reference

| What you want to do | Command                       |
| ------------------- | ----------------------------- |
| Check what changed  | `git status`                  |
| Get latest changes  | `git pull`                    |
| Create a branch     | `git checkout -b branch-name` |
| Switch branches     | `git checkout branch-name`    |
| Add changes         | `git add .`                   |
| Save a checkpoint   | `git commit -m "message"`     |
| Upload changes      | `git push`                    |
| See branches        | `git branch`                  |
| See commit history  | `git log --oneline`           |

---

# ⭐ The Golden Rules

### 1. **Don't work directly on `main`.**

### 2. **Pull before you start working.**

### 3. **Make a branch for your work.**

### 4. **Commit meaningful changes.**

### 5. **Push your branch.**

### 6. **Use Pull Requests to merge into `main`.**

### 7. **Don't commit passwords, API keys, or other secrets.**

### 8. **When in doubt, ask before running potentially destructive Git commands.**

---

# 📚 Additional Resources

If you're completely new to Git, the official Git documentation is a good reference:

https://git-scm.com/doc

GitHub's documentation is also useful:

https://docs.github.com/
