# The Archadian Alchemist

The Archadian Alchemist introduces an alchemy system that allows you to alter elemental properties and enhance equipment attributes through a specialized alchemist, unlocking new strategic possibilities as the laboratory progresses.

---

## CI Automation

### 1. Create a Git Tag

To trigger the CI workflow, create a tag in the format `vX.Y.Z`.

```bash
git tag v1.0.0
git push origin v1.0.0
```

### 2. Create a GitHub Release

After pushing the tag, you can create a release via CLI:

```bash
gh release create v1.0.0 --title "v1.0.0" --notes "Initial release"
```

Or manually via GitHub:

- Go to your repository
- Click **Releases > Draft a new release**
- Select the tag you pushed (e.g., `v1.0.0`)
- Enter a title and description
- Click **Publish release**

```bash
💡 Write meaningful titles and descriptions, they’ll be automatically added to the changelog.
```

---

## What the GitHub Action Does

Once a release is published, the GitHub Action will automatically:

1. **Update the version** in `fomod/Info.xml` to match the release tag.
2. **Append release notes** to `CHANGELOG.md`, maintaining a complete release history in **timeline format**.
3. **Compress** the `data/` and `fomod/` directories into a ZIP archive named: `YourRepositoryName-vX.Y.Z.zip`
4. **Upload** the ZIP file to the corresponding GitHub Release as a downloadable asset.
