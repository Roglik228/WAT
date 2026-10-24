# Provenance and history preservation

| Source branch | Pinned commit |
|---|---|
| main | 55bd0045820d5d55434ab234f778b8396c2cf7f3 |
| 1-Rok | e857fba25ca8cbfaa68d4760c85d71a68a65c026 |
| 2-Rok | 8f0b3ccf6bc4d92e7cc7587c6894c24b71e479ac |
| 3-Rok | 1f20a325b373e71179ee423c77ee10be05f17503 |

Every downloaded source file was verified against its Git blob SHA. Third-year files are a subset of the pinned main snapshot by path and blob hash, so an extra duplicate archive is unnecessary. Its commit is recorded separately.

The separate private backup contains exact main/first-year/second-year files and the original Git tree inventory. The migration manifest records each original path, SHA-256 and archive treatment. The ZIP itself is a file snapshot, not a Git clone: the existing remote repository and branches retain history.

When publishing, create a new branch from pinned main and keep year branches. Incorporating their histories would require explicit merge parents, not a reset or force-push. No branch deletion or history rewrite is proposed.

## Source transformations

- Pipeline and embedded source files: copied byte-for-byte.
- Crypto: renamed teaching snippets to .sage/.py; added missing sample/choice imports to two copies.
- Keylogger: non-executable static text reference, reference-only header and three collection identifiers removed; originals retained privately.
- Student-ID documents: text-only redacted exports; originals retained privately.
- README files and SVG diagrams: newly prepared from reviewed source/report facts.
