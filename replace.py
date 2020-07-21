from os import *
from os.path import *

ot = ["if_number_of_array_set_one","basic",".git"]
tt = ["test","makein"]
def mpath(lib,c):
    pathf="/"
    for i in range(len(lib)):
        if type(lib[i]) is list:
            for ii in range(len(lib[i])):
                pathf+=lib[i][ii]
                if ii<len(lib[i])-1:
                    pathf+=c
                else:
                    pathf+='.'
        else:
            pathf+=lib[i]
            if i<len(lib)-1:
                pathf+='.'
    return pathf
def makepath(lia, lib):
    #print(lia)
    #print(lib)
    pathd="./"
    for i in range(len(lia)):
        pathd+=lia[i]
        if i<1:
            pathd+='_'
    pathf=mpath(lib,'_')
    if type(lib[0]) is list:
        lib[0][0]=lia[1]
    else:
        lib[0]=lia[1]

    pathm=mpath(lib,'.')

    print(pathf,"     ",pathm)
    #replace(pathd+pathf,pathd+pathm)

for a in listdir("."):
    if isdir(a):
        conflag=False
        for o in ot:
            if a==o:
                conflag=True
                break
        if conflag==True:
            continue
        lia=a.split("_")
        #print(li)
        for b in listdir("./"+a):
            lib=b.split(".")
            if lib[-1] == "cpp":
                t=False
                for k in tt:
                    if lib[0].find(k)==0:
                        t=True
                        break
                if t:
                    continue
                else:
                    lik=lib[0].split("_")
                    if len(lik)>1:
                        lib[0] = lik
                    #print(lib)
                    makepath(lia,lib)
