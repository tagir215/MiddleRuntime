from pathlib import Path
import os

folder = Path("MidComp")



for item in folder.iterdir():
    lines = []
    with open(item, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    name = item.stem

    writeLines = []

    for line in lines:
        line = line.replace("reflect", f"reflect{name}")
        writeLines.append(line)

    for line in writeLines:
        print(line)

    with open(item, 'w', encoding='utf-8') as file:
        file.writelines(writeLines)



