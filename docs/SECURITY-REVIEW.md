# Publication security review

## Prepared exclusions and changes

- mail.txt is excluded as instructed by the owner. It contains credential-like account notes; their validity was not tested.
- The original ONI executable, reports and supporting files are retained in a separate private backup. The binary may embed collection identifiers; it was not run or disassembled.
- The static source reference replaces the collection host, form path and field identifier. It is not a build target.
- Documents containing the identified student number in extracted text are replaced by text exports without that number or email addresses.
- Academic question banks, notes and other materials are retained at the owner's request.

## Review coverage

All 151 downloaded snapshot files were inventoried and verified against Git blob hashes. Available text was extracted from PDFs, DOCX and supported text formats, including documents inside ZIP archives. This supports triage for emails, IP addresses, student identifiers, private-key markers and collection URLs.

This is not an exhaustive visual/OCR or binary audit. Retained archival reports may contain names, certificate subjects, usernames, email addresses, machine names or lab addresses on screenshots. These original screenshots are **not described as redacted**. New SVG illustrations contain no real account or endpoint identifiers.

Private lab addresses are not credentials or public Internet endpoints; they need context rather than automatic removal. Public project summaries use generic labels.

## Remaining decisions

1. Rotate/revoke any genuine credentials from the removed notes. Removing a new-tree file does not remove old commits, branches, clones or caches.
2. Review remaining original screenshots before public archive publication. Text extraction cannot exclude secrets shown only in images.
3. Confirm rights where needed for third-party material; no license is assigned by this reorganization.
4. Any sensitive-history purge would be a separate coordinated action with explicit approval. No force-push or history rewrite has been performed.

Publication is proposed through a separate branch and draft pull request. The main and academic branches are retained; no history rewrite is performed.
