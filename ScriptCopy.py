import os
import shutil

# 定义当前目录为 PokemonHackAssistant 根目录（Python 脚本所在位置）
base_directory = os.getcwd()
release_directory = os.path.join(base_directory, 'Release')

# 需求 2: 如果 Release 目录存在，先删除它；如果不存在，则创建它
if os.path.exists(release_directory):
    print(f"Release folder exists, removing: {release_directory}")
    shutil.rmtree(release_directory)

print(f"Creating Release folder: {release_directory}")
os.makedirs(release_directory)

# 要拷贝的目录列表
txt_folders = [
    os.path.join(base_directory, 'PokemonMemHack'),
    os.path.join(base_directory, 'PokemonRomViewer')
]

# 1. 拷贝两个文件夹下的所有 .txt 文件（不递归，仅当前层级）到 Release 目录
for folder in txt_folders:
    for filename in os.listdir(folder):
        if filename.endswith(".txt"):
            source_file = os.path.join(folder, filename)
            destination_file = os.path.join(release_directory, filename)
            
            # 拷贝 .txt 文件
            print(f"Copying {source_file} to {destination_file}")
            try:
                shutil.copy(source_file, destination_file)
                print(f"Successfully copied {filename} to Release folder")
            except Exception as e:
                print(f"Failed to copy {filename}: {e}")

# 2. 拷贝两个 .exe 文件到 Release 目录
exe_files = [
    os.path.join(base_directory, 'PokemonRomViewer', 'Debug', 'PokemonRomViewer.exe'),
    os.path.join(base_directory, 'PokemonMemHack', 'Debug', 'PokemonMemHack.exe')
]

for exe_file in exe_files:
    if os.path.exists(exe_file):
        destination_file = os.path.join(release_directory, os.path.basename(exe_file))
        print(f"Copying {exe_file} to {destination_file}")
        try:
            shutil.copy(exe_file, destination_file)
            print(f"Successfully copied {os.path.basename(exe_file)} to Release folder")
        except Exception as e:
            print(f"Failed to copy {os.path.basename(exe_file)}: {e}")
    else:
        print(f"{exe_file} does not exist.")
