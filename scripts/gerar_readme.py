import os
import urllib.parse

BASE_DIR = "SBC - fase zero"
PHASES = {
    "Fase0-22": 12,
    "Fase0-25": 12,  # Ajustado para corresponder ao README
}

def format_line(phase, letter, name, solved):
    folder_name = f"{letter.lower()} - {name.lower()}"
    folder_path = f"{BASE_DIR}/{phase}/{folder_name}"
    github_url = f"https://github.com/CSFesta/Marathon-Solutions/tree/main/{urllib.parse.quote(folder_path)}"

    full_path = os.path.join(folder_path)
    print(f"Verificando pasta: {full_path}")
    if not os.path.isdirguo(full_path):
        print(f"Pasta não encontrada: {full_path}")
        return f"- ⬜ **{letter} - {name}** (Pasta não encontrada)"
    
    is_solved = any(f.endswith(('.cpp', '.py')) for f in os.listdir(full_path))
    print(f"Arquivos .cpp/.py encontrados em {full_path}: {is_solved}")
    
    if is_solved:
        solved.append(1)
        return f"- ✅ [**{letter} - {name}**]({github_url})"
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
        print(f"Processando fase: {phase_path}")
        try:
            folders = sorted(os.listdir(phase_path))
        except FileNotFoundError:
            print(f"Diretório não encontrado: {phase_path}")
            content.append(f"## 🚀 [**{phase.replace('-', ' - ')} (0 / {total})**](https://github.com/CSFesta/Marathon-Solutions/tree/main/{urllib.parse.quote(f'{BASE_DIR}/{phase}')}) \n")
            content.append(f"- ⚠️ **Diretório da fase não encontrado**\n")
            continue

        content.append(f"## 🚀 [**{phase.replace('-', ' - ')} ({len(solved_counter)} / {total})**](https://github.com/CSFesta/Marathon-Solutions/tree/main/{urllib.parse.quote(f'{BASE_DIR}/{phase}')}) \n")

        lines = []
        for folder in folders:
            if " - " in folder:
                try:
                    letter, name = folder.split(" - ", 1)
                    line = format_line(phase, letter, name, solved_counter)
                    lines.append(line)
                except ValueError:
                    print(f"Formato inválido para a pasta: {folder}")
                    lines.append(f"- ⚠️ **Formato inválido: {folder}**")
            else:
                print(f"Pasta ignorada (sem ' - '): {folder}")

        content[-len(lines) - 1] = content[-len(lines) - 1].replace(f"(0 / {total})", f"({len(solved_counter)} / {total})")
        content.extend(lines)
        content.append("")  # Quebra de linha entre fases

    with open("README.md", "w", encoding="utf-8") as f:
        f.write("\n".join(content))

if __name__ == "__main__":
    generate_readme()