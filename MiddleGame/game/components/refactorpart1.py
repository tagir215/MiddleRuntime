from pathlib import Path
import os

folder = Path("MidComp")


template = """
    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<MODIFYME>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMARIOMARIO(X)
        #undef X
    }
}"""


for item in folder.iterdir():
    if ".h" in item.suffix:
        print(item.stem)
        name = item.stem
        uppercaseName = item.stem.upper()

        newText = template.replace("MODIFYME", name)
        newText = newText.replace("MARIOMARIO", uppercaseName)
        replacingLines = [line + '\n' for line in newText.splitlines()]

        lines = []
        with open(item, 'r', encoding='utf-8') as file:
            lines = file.readlines()

        insert_index = len(lines) - 1
        writeLines = []
        index = 0
        for line in lines:
            line = line.replace(": public middle::Serializable", "")
            if index != insert_index:
                writeLines.append(line)
            else:
                for replacingLine in replacingLines:
                    writeLines.append(replacingLine)
            index = index + 1


        for line in writeLines:
            print(line)
        with open(item, 'w', encoding='utf-8') as file:
            file.writelines(writeLines)





