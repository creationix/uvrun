{
  "targets": [
    {
      "target_name": "uvrun",
      "sources": ["uvrun.cc"],
      "variables": {
        "node_version": '<!(node --version | sed -e "s/^v\([0-9]*\\.[0-9]*\).*$/\\1/")',
      }
    }
  ]
}
