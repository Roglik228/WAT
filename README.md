<div align="center">

# Andrii Godlevskyi
### Cybersecurity & Network Engineering Portfolio

**Junior SOC Analyst · Junior Security Analyst · Junior Network Engineer**

Academic work from WAT: traffic analysis, Windows security, vulnerability assessment, networks and cryptographic protocols.

[Projects](#featured-projects) · [Skills](#skills-and-evidence) · [Coursework](coursework/archive/README.md)

</div>

## Featured projects

<table>
<tr><td width="50%" valign="top">

### 01 · PKI, HTTPS & VPN
[Explore the lab →](projects/pki-https-vpn/README.md)

Root/intermediate CA, Apache HTTPS and Wireshark HTTP/TLS inspection, plus an OpenVPN lab.

**OpenSSL · Wireshark · Apache · Linux · OpenVPN**

</td><td width="50%" valign="top">

### 02 · Windows vulnerability assessment
[Read the assessment →](projects/windows-vulnerability-assessment/README.md)

Nessus findings on a Windows 11 lab host, risk prioritization and a proposed remediation/retest plan.

**Nessus · Windows · SMB · TLS**

</td></tr>
<tr><td valign="top">

### 03 · Windows keylogger analysis
[Read the static analysis →](projects/windows-keylogger-analysis/README.md)

Defensive review of an academic C++ keylogger: persistence, input collection, host artifacts and network behavior.

**C++ · WinAPI · Static analysis**

</td><td valign="top">

### 04 · Distributed protocol pipeline
[Explore the source →](projects/distributed-pipeline/README.md)

Four processes pass bytes over TCP, XML-RPC and UDP before printing hexadecimal output.

**Perl → Python → PHP → C · Sockets**

</td></tr>
<tr><td valign="top">

### 05 · Cryptographic protocol simulations
[Explore the simulations →](projects/cryptography/README.md)

Diffie–Hellman, Lamport hash chains, Shamir sharing, signature simulations and Blum coin tossing.

**SageMath · Python · SHA3-512**

</td><td valign="top">

### 06 · Embedded keypad & LCD
[Explore the firmware →](projects/embedded-keypad/README.md)

8051 firmware scans a matrix keypad and implements multi-tap text input on an LCD.

**C · 8051 · Proteus · GPIO**

</td></tr>
</table>

## Skills and evidence

| Area | Project |
|---|---|
| Traffic inspection and certificate trust | [PKI / HTTPS / VPN](projects/pki-https-vpn/README.md) |
| Vulnerability triage and remediation planning | [Windows assessment](projects/windows-vulnerability-assessment/README.md) |
| Windows persistence and host artifacts | [Keylogger analysis](projects/windows-keylogger-analysis/README.md) |
| TCP framing, RPC and UDP | [Distributed pipeline](projects/distributed-pipeline/README.md) |
| Protocol reasoning and finite fields | [Cryptography](projects/cryptography/README.md) |
| Low-level programming and state handling | [Embedded C](projects/embedded-keypad/README.md) |

## Repository structure

```text
projects/
├── pki-https-vpn/                       PKI, HTTPS, traffic analysis and VPN
├── windows-vulnerability-assessment/    Nessus findings and remediation plan
├── windows-keylogger-analysis/          Static analysis and Windows artifacts
├── distributed-pipeline/               Perl / Python / PHP / C networking
├── cryptography/                       Cryptographic protocol simulations
└── embedded-keypad/                    8051 firmware and Proteus circuit

coursework/archive/
├── 1-Rok/                              First-year coursework by discipline
├── 2-Rok/                              Second-year coursework by discipline
└── main/                               Later coursework by discipline

docs/LICENSING.md                        Authorship and reuse information
```

Each project README describes its purpose, technologies, files, setup and available results. Source code, diagrams and laboratory reports are linked from the project pages.

## Coursework

The [coursework archive](coursework/archive/README.md) contains laboratory reports, programming exercises, lecture notes and question banks, grouped by academic year and discipline.

See [authorship and reuse information](docs/LICENSING.md).
