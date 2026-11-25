# SmartRetail P3 — Recommendation & Identity Matcher

## 1. Team Members & Lecturer
* **Lecturer:** `vvvanthe`
* **Group 06 Members:**
  * **Khanh** (Team Leader) – GitHub: `Ukakaka2802`
  * **Nhi** – GitHub: `phuowngnhi`
  * **Hoang** – GitHub: `hoangho31261028871-sys`

## 2. Problem Specification
* **Input:** 4 CSV files (`products.csv`, `customer_events.csv`, `identity_links.csv`, `transactions.csv`), with optional CLI arguments `[session_id]` and `[K]` (default `K = 3`).
* **Processing:** Link anonymous sessions (`session_id`) to known customers (`customer_id`), infer preferences (category, brand, budget) using 1 of 3 branches (a), (b), or (c), score the product catalogue (up to 10 points, excluding items exceeding the budget), and rank the Top-K recommendations.
* **Output:** Identity match rate statistics, chosen inference branch, inferred preferences, and Top-K recommended products for each session.

## 3. Build & Run Instructions
```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp -o bin/p3
./bin/p3 data/sample
```

## 4. Assumptions & Limitations
* CSV fields contain no commas and no Vietnamese diacritics.
* Walk-in customer transactions (`customer_id = GUEST`) are ignored when inferring preferences.
* If a session is linked to multiple customers in `identity_links.csv`, only the first occurrence is kept.
* Invalid lines (non-positive quantity, unknown product code, empty `customer_id`, or a session not found in the event file) are skipped with a warning and line number printed to `cerr`.

## 5. Boundaries (What the Project Does NOT Do)
* The program uses `identity_links.csv` only to link sessions to customers.
* It does not generate new behaviour events.
* It does not calculate or decide inventory levels or orders.

## 6. Task Assignment Table
| ID | Task | Function / file | Assignee | Reviewer | Flowchart | PR |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| T01 | Repo skeleton & PR template | `.gitignore`, `.github/`, folders | Khanh | Nhi | not needed | #1, #2 |
| T02 | Core branch selection & scoring | `selectBranch()`, `scoreProduct()` | Khanh | Hoang | yes | - |
| T03 | Read products & transactions CSV | `loadProducts()`, `loadTransactions()` | Khanh | Nhi | yes | - |
| T04 | Read events & identity links CSV | `loadEvents()`, `loadIdentityLinks()`, `findLink()`, `sessionExists()` | Nhi | Khanh | yes | - |
| T05 | Preference inference (category, brand, budget) | `inferPreferences()` | Nhi | Hoang | yes | - |
| T06 | Sort Top-K & print report | `sortRecommendations()`, `printReport()` | Hoang | Khanh | yes | - |
| T07 | CLI argument parser & main pipeline | `parseArgs()`, `main()` | Hoang | Nhi | yes | - |
| T08 | Test cases (TC01–TC07) & expected outputs | `tests/test_cases.md`, `tests/expected/` | Khanh | Nhi | not needed | - |
| T09 | System architecture documentation | `docs/architecture.md` | Nhi | Hoang | not needed | - |
| T10 | Presentation slides | `docs/slides.pdf` | Hoang | Khanh | not needed | - |
| T11 | CSV helper & binary search | `splitCsv()`, `binarySearchProduct()`, `findProduct()` | Nhi | Khanh | yes | - |

## 7. AI Declaration & References
* **AI Tool Used:** Gemini.
* **Purpose:** Assisted in setting up the GitHub repository structure, Pull Request template, and drafting the task assignment table in compliance with course guidelines.
