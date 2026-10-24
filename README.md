<div align="center">

# Andrii Godlevskyi
### Cybersecurity & Network Engineering Portfolio

**Junior SOC Analyst · Junior Security Analyst · Junior Network Engineer**

Academic work from WAT: traffic analysis, Windows security, vulnerability assessment, networks and cryptographic protocols.

[Projects](#featured-projects) · [Skills](#skills-and-evidence) · [Coursework](coursework/archive/README.md) · [Validation](docs/VALIDATION.md)

</div>

## Featured projects

<table>
<tr><td width="50%" valign="top">

### 01 · PKI, HTTPS & VPN
[Explore the lab →](projects/pki-https-vpn/README.md)

Root/intermediate CA, Apache HTTPS and Wireshark HTTP/TLS inspection, plus an OpenVPN lab.

**OpenSSL · Wireshark · Apache · Linux · OpenVPN**

Evidence: laboratory reports; no PCAP or deployable PKI included.

</td><td width="50%" valign="top">

### 02 · Windows vulnerability assessment
[Read the assessment →](projects/windows-vulnerability-assessment/README.md)

Nessus findings on a Windows 11 lab host, risk prioritization and a proposed remediation/retest plan.

**Nessus · Windows · SMB · TLS**

Evidence: academic report. Remediation is not independently verified.

</td></tr>
<tr><td valign="top">

### 03 · Windows keylogger analysis
[Read the static analysis →](projects/windows-keylogger-analysis/README.md)

Defensive review of an academic C++ keylogger: persistence, input collection, host artifacts and network behavior.

**C++ · WinAPI · Static analysis**

Evidence: source review. No sample execution or validated EDR detection.

</td><td valign="top">

### 04 · Distributed protocol pipeline
[Explore the source →](projects/distributed-pipeline/README.md)

Four processes pass bytes over TCP, XML-RPC and UDP before printing hexadecimal output.

**Perl → Python → PHP → C · Sockets**

Evidence: source code; network execution was blocked in this environment.

</td></tr>
<tr><td valign="top">

### 05 · Cryptographic protocol simulations
[Explore the simulations →](projects/cryptography/README.md)

Diffie–Hellman, Lamport hash chains, Shamir sharing, signature simulations and Blum coin tossing.

**SageMath · Python · SHA3-512**

Teaching implementations with explicit limitations.

</td><td valign="top">

### 06 · Embedded keypad & LCD
[Explore the firmware →](projects/embedded-keypad/README.md)

8051 firmware scans a matrix keypad and implements multi-tap text input on an LCD.

**C · 8051 · Proteus · GPIO**

Evidence: firmware and circuit project; no fresh simulator/hardware run.

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

## Repository map

```text
projects/             Six selected technical projects
coursework/archive/   Remaining work by academic branch and discipline
docs/                 Validation, provenance and publication review
```

This portfolio presents academic work. Descriptions distinguish historical report results, static observations and checks performed during preparation. No employment, production deployment, incident-response experience or certification is implied.

See [provenance](docs/PROVENANCE.md), [security review](docs/SECURITY-REVIEW.md) and [licensing](docs/LICENSING.md). Original branches and Git history must be retained when applying this reorganization.
