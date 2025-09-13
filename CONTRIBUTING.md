As of now, this project is not accepting code contributions.
If you wish to report a bug, please refer to the [Reporting a Bug](#reporting-a-bug) section.
If you wish to request a feature, please refer to the [Requesting a Feature](#reporting-a-feature) section.

For either of these, there isn't a formalized format.
Just make sure to be as descriptive as possible without being too wordy.

# Reporting a Bug
This project is not currently accepting PRs for bug fixes.
It does accept bug reports, but in a very strict format.
Bug reports shall be created in the for of PRs to the unit testing.
Write unit tests that fail _because_ of the bug.
Before creating a PR, ensure that the tests fails, and that it fails _because_ of the bug.

## Why the weird and strict format
This format ensures two things:
- reports are valid and verifiable
- each report works to make the code **more robust** moving forward

### Valid and Verifiable
There has been a rise in bogus bug reports in popular repositories driven by LLMs that are over eager to create bug reports.
The current mitigation to these hallucinated bugs is to simply have a disclosure if AI is involved in the creation of the report.
This solution does not really filter invalid bug reports from the valid ones.
It only filters the (self reported) AI assisted reports from the rest.
I personally do not care if AI is used to create the report or not.
I only care that it is **valid**.
A unit test is the most sure way to test a bug report's validity.

### More robust moving forward
If a bug report has been proven to be valid by the unit test in its PR, a fix will be made by the maintainer.
Once the bug has been fixed, the unit test will be merged.
This ensures that the a regression that leads to the same bug will not be introduced to the code in the future.

# Requesting a Feature
To request a feature, create an issue and describe the feature and its use case.
