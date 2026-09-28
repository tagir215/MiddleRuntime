from pathlib import Path
import os

folder = Path("MidComp")


template = """template<typename V>
              static void reflect(middle::Shape& shape, V& v) {
                  auto comp = middle::getComponent<MODIFYME>(shape);
              #define X(f) v(#f, comp->f);
                  MIDDLEMODIFYMEUPPERCASE(X)
              #undef X
              }"""


for item in folder.iterdir():
    if "cpp" in item.suffix:
        print(item.stem)
        name = item.stem
        uppercaseName = item.stem.upper()

        newText = template.replace("MODIFYME", name)
        newText = template.replace("MODIFYMEUPPERCASE", uppercaseName)
        replacingLines = newText.splitlines()

        lines = []
        with open(item, 'r', encoding='utf-8') as file:
            lines = file.readlines()

        size = len(lines)
        lines.insert(size-2, replacingLines)

        with open(item, 'w', encoding='utf-8') as file:
            file.writelines(lines)




