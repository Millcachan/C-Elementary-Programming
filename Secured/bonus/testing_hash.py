##
## EPITECH PROJECT, 2023
## B-CPE-110-STG-1-1-secured-titouan.pradoura
## File description:
## testing_hash.py
##

from random import randint
import subprocess


def generate_key(nb_key):
    subprocess.run("make re", shell = True, executable="/bin/bash")
    list_key = []
    list_hash = []
    while(len(list_key) != nb_key):
        key = ""
        for y in range(randint(0, 25)):
            key += chr(randint(40, 125))
        list_key.append(key)
        list_key = list(set(list_key))
    for i in range(nb_key):
        command = f"./bonus/hash '{list_key[i]}' 3"
        result = subprocess.run(command, shell = True, stdout=subprocess.PIPE, executable="/bin/bash")
        list_hash.append(result.stdout.decode('utf-8').strip())
    set_hash = set(list_hash)
    dico_occur = {}
    for hashed in set_hash:
        if chr(int(hashed) % 25 + 48) in dico_occur.keys():
            dico_occur[chr(int(hashed) % 25 + 48)] += 1
        else:
            dico_occur[chr(int(hashed) % 25 + 48)] = 1
    print(dico_occur)

generate_key(1)

