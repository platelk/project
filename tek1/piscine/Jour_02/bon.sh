cat passwd | cut -d: -f5 | grep -E "(^| )bon$" | wc -l
