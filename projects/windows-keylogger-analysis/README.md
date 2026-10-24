# Static analysis of an academic Windows keylogger

[← Portfolio](../../README.md)

A defensive case study of the ONI keylogger. Despite hardware-diagnostics branding, its source records keystrokes and window context, attempts persistence and sends data outward.

![Source-observed behavior](assets/behavior.svg)

## Technologies and review method

C++, WinAPI, registry/file I/O and WinINet. The original project also contains a Python decoder. Review was static: no executable was launched, no collection endpoint contacted and no credentials tested.

The [source reference](reference/main.cpp.disabled.txt) is non-executable text with the collection host, form path and field identifier removed. This project contains the static reference, a behavior diagram and defensive analysis notes.

## Source observations

| Area | Evidence | Investigation relevance |
|---|---|---|
| Persistence | InstallIfNeeded copies into AppData and attempts an HKCU Run value. | Correlate registry writes and executable creation. |
| Input | PollingLoggerEngine polls key states and foreground window titles. | Ordinary Windows logs do not expose every API call. |
| Storage | Hardware.dat holds captured text. | Preserve before cleanup. |
| Encoding | EncryptXORBase64 applies a fixed XOR byte and Base64. | Reversible obfuscation, not robust encryption. |
| Network | NetworkExfiltrationWorker attempts HTTPS form submission after a character threshold. | Correlate process/network/file evidence; TLS metadata does not reveal the POST body. |
| Deletion | SelfDestruct removes artifacts and starts a command process. | Do not invoke during evidence collection. |

## Defensive review workflow

Read the source reference and [analysis notes](ANALYSIS.md). For a suspected real event, preserve evidence, isolate through the organization's response process, establish scope and assess credential exposure. This repository does not automate response.

## Results and limits

Result: a source-backed behavior map and proposed investigation workflow. Persistence success, data delivery, antivirus evasion, impact and binary/source equivalence were not independently tested. No validated SIEM rules, incident metrics or EDR results are claimed. Academic software development is not evidence of operating an APT.
