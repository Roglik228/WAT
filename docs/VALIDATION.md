# Validation log

Prepared on 24 October 2026.

| Check | Result | Scope |
|---|---|---|
| Original Git blob hashes | PASS · 151 files | Main, first-year and second-year downloaded snapshots exactly match pinned tree entries. |
| Third-year snapshot | PASS | Every file in 3-Rok matches main by path and blob SHA. |
| Exact original backup | PASS | All 151 originals retained in a separate private local ZIP; not part of the public tree. |
| Lamport demonstration | PASS · 3 verifications | Executed the default Python-only three-login simulation. |
| Python TCP/RPC bridge | BLOCKED | Local socket connections rejected by the environment (WinError 10013); not a test of project correctness. |
| Complete Perl/Python/PHP/C pipeline | NOT RUN | Required Perl/PHP/GCC tools are absent and local connections are restricted. |
| SageMath simulations | NOT RUN | SageMath is unavailable. |
| 8051 firmware/Proteus | NOT RUN | Target compiler/simulator unavailable. |
| ONI keylogger | STATIC ONLY | No execution, endpoint contact, credentials testing or binary/source equivalence check. |
| PKI/HTTPS/VPN and Nessus | REPORT REVIEW | Historical report evidence, no fresh scan, capture, deployment or remediation. |

The diagrams are recreated explanations, not screenshots from a new run. No benchmark, security efficacy or production readiness result is claimed.
