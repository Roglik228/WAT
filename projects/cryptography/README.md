# Cryptographic protocol simulations

[← Portfolio](../../README.md)

Six academic simulations expose intermediate values and protocol steps for learning.

![Protocol families](assets/protocols.svg)

## Technologies and contents

Python 3, SageMath, SHA3-512, modular arithmetic, finite fields and polynomial interpolation.

| File in src/ | Topic | Limitations |
|---|---|---|
| diffie_hellman.sage | Three-party shared-key calculation | Small parameters; printed private exponents |
| lamport.py | Multiuser hash-chain authentication | Predictable seeds; chain exhaustion unhandled |
| shamir.sage | Polynomial shares/Lagrange reconstruction | Small field; leading coefficient can be zero |
| signature_simulation.sage | Signature confirmation/altered-input cases | Local private state; not independent network verification |
| blum_coin.sage | Blum coin tossing/invalid cases | Small parameters; not independently audited |
| blind_signature.sage | Blinding/signing/tampering cases | Teaching parameters and exposed intermediate secrets |

## Run

```sh
python3 src/lamport.py
sage src/diffie_hellman.sage
sage src/shamir.sage
```

Use an installed SageMath environment for every .sage file. Original .txt snippets use Sage syntax such as ^ and P.<x>; .sage invokes the [Sage preparser](https://doc.sagemath.org/html/en/reference/misc/sage/misc/persist.html). Missing sample/choice imports were added to two copies. The original six files are preserved unchanged in coursework/archive/2-Rok/PK/.

## Results and limits

The default Lamport demonstration was executed and its three successful verifications checked; see [result](results/lamport-check.md). SageMath is unavailable here, so other simulations were not run. Source-visible positive/negative scenarios are not advertised as passing tests.

The signature simulation returns success only inside an if ok and verbose branch, so verbose=False can report failure even when comparisons succeed. This limitation was documented rather than hidden. No implementation provides production key generation, constant-time execution, authenticated transport or an independently reviewed construction. Do not use it to protect real data.
