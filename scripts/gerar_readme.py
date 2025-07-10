import os

BASE_DIR = "SBC - fase zero"
PHASES = {
    "Fase0-22": 12,
    "Fase0-25": 13,
}

def format_line(phase, letter, name, solved):
    # Formata o nome do diretório
    folder_name = f"{letter.lower()} - {name.lower().replace(' ', '%20')}"
    folder_path = f"{BASE_DIR}/{phase}/{folder_name}"
    github_url = f"https://github.com/CSFesta/Marathon-Solutions/tree/main/{folder_path.replace(' ', '%20')}"

    full_path = os.path.join(folder_path)
    is_solved = os.path.isdir(full_path) and any(
        f.endswith(('.cpp', '.py')) for f in os.listdir(full_path)
    )

    if is_solved:
        solved.append(1)
        return f"- ✅ [**{letter} - {name}**]({github_url})"
    else:
        return f"- ⬜ **{letter} - {name}**"

def generate_readme():
    content = [
        "## ⚙️ Organização\n",
        "Cada pasta contém:",
        "- Códigos em **C++** (principalmente) e **Python** (em casos específicos)",
        "- Comentários explicativos sempre que necessário",
        "- Nome do problema + link oficial + breve explicação/resumo",
        "- Nível de dificuldade (com base em frequência de resolução: ex. 1/12 se for o problema mais resolvido em uma prova com 12 questões)\n",
        "### 🔗 Clicando nas questões resolvidas, você será direcionado para a pasta de resolução daquela questão!",
        "### ✅ Resolvido  ⬜ Não resolvido\n",
        "---\n"
    ]

    for phase, total in PHASES.items():
        solved_counter = []
        phase_path = os.path.join(BASE_DIR, phase)
        content.append(f"## 🚀 [**{phase.replace('-', ' - ')} (0 / {total})**](https://github.com/CSFesta/Marathon-Solutions/tree/main/{BASE_DIR.replace(' ', '%20')}/{phase}) \n")

        lines = []
        folders = sorted(os.listdir(phase_path))
        for folder in folders:
            if " - " in folder:
                letter, name = folder.split(" - ", 1)
                line = format_line(phase, letter, name, solved_counter)
                lines.append(line)

        content.extend(lines)
        content[-len(lines) - 1] = content[-len(lines) - 1].replace("(0 /", f"({len(solved_counter)} /")

        content.append("")  # quebra de linha entre fases

    with open("README.md", "w", encoding="utf-8") as f:
        f.write("\n".join(content))

if __name__ == "__main__":
    generate_readme()
