# TP Linux



### 1. Commandes de base - Gestionnaire de fichiers

​	*Pas de question a traiter dans cette partie.*



### 2. Editeurs de textes

#### 	2.1 Liste des éditeurs de texte

​	*Pas de question a traiter dans cette partie*



####    	2.2 Apprentissage de vi

​	**1. ** Correction du fichier Descartes.err

​	**2. ** Jeuvi -> Obtention du rang “merveilleux” avec un score de 21/27



### 3. Questions de cours

####   	3.1 Montage

​	**1. **
  	

  	**2. **Liste des montages disponnibles: "cat /etc/mtab". Les montages disponnibles sont consignés au sein du fichier "mtab" dans le repertoire "/etc". La liste des montages actuelement montés est disponnible avec la commande "cat /etc/fstab".

​	 **3.** En regardant le manuel de la commande "mount", on observe que les types de montage les plus courant sont : ext2, ext3, ext4, xfs, btrfs, vfat, sysfs, proc, nfs et cifs.



#### 	3.2 Droits d’accès

​	**1. ** Pour verifier les droits d'acces en lecture d'un repertoire, j'ai tester le senario suivant:

* Creation d'un dossier "test" avec un fichier a l'interieur "test/file"
* Attribution de tout les droits pour tester le comportement normal du dossier.
* On test des commandes de base (cd, ls, ..)
* On enleve le droit de lecture.
* On regarde si on peut toujours effectuer les même commandes.

```bash
$ mkdir test
$ touch test/file
$ chmod 700 test
$ ls -ls
	total 0
	drwxr-xr-x 3 cthomasset users 18 17 sept. 15:38 .
	drwxr-xr-x 4 cthomasset users 90 17 sept. 15:34 ..
	drwx------ 2 cthomasset users 18 17 sept. 15:39 test

$ ls test
file

$ chmod 300 test 
$ ls -ls
	total 0
	drwxr-xr-x 3 cthomasset users 18 17 sept. 15:38 .
	drwxr-xr-x 4 cthomasset users 90 17 sept. 15:34 ..
	d-wx------ 2 cthomasset users 18 17 sept. 15:39 test

$ ls test
ls: impossible d\'ouvrir le répertoire \'test\': Permission non accordée

$ cd test
$ vi file
```

On ne peut pas afficher le contenu du dossier test sans le droit de lecture, on perd le droit de lecture du repertoire. Mais on peut toujours acceder a son sous-contenu à condition de se souvenir des noms des sous fichiers. On peut aussi toujours 'cd' a travers (car on possede toujours le droit d'execution).

**2. ** Pour verifier les droits d'acces en ecriture d'un repertoire, j'ai tester le senario suivant:

* Creation d'un dossier "test" avec un fichier a l'interieur "test/file"
*  Attribution de tout les droits pour tester le comportement normal du dossier.
* On test des commandes de base (cd, ls, ..)
* On enleve le droit d'écriture.
* On regarde si on peut toujours effectuer les même commandes.

```shell
$ mkdir test
$ touch test/file
$ chmod 700 test
$ ls -ls
	total 0
	drwxr-xr-x 3 cthomasset users 18 17 sept. 15:38 .
	drwxr-xr-x 4 cthomasset users 90 17 sept. 15:34 ..
	drwx------ 2 cthomasset users 18 17 sept. 15:39 test

$ ls test
file

$ chmod -w test 
$ ls -ls
	total 0
	drwxr-xr-x 3 cthomasset users 18 17 sept. 15:38 .
	drwxr-xr-x 4 cthomasset users 90 17 sept. 15:34 ..
	dr-x------ 2 cthomasset users 18 17 sept. 15:39 test

$ touch file2
touch: impossible de faire un touch \'test/file2\': Permission non accordée

$ rm file
rm: impossible de supprimer \'test/file\': Permission non accordée

$ ls test
file

$ cd test
$ vi file
```

Les commandes qui on attrait a la modification du contenu du dossier ne fonctionnent plus. On ne peut pas ajouter ou supprimer des fichier à l'interrieur de ce repertoire. Mais on peut toujours ls et cd (ces commandes ne modifient pas le fichier special de type repertoire).



**3. ** Pour verifier les droits en execution d'un repertoire, j'ai tester le senario suivant:

* Creation d'un dossier "test" avec un fichier a l'interieur "test/file"
* Attribution de tout les droits pour tester le comportement normal du dossier.
* On test des commandes de base (cd, ls, ..)
* On retire le droit en ecriture.
* On regarde si on peut toujours effectuer les même commandes.

```shell
$ mkdir test
$ touch test/file
$ chmod 700 test
$ ls -ls
	total 0
	drwxr-xr-x 3 cthomasset users 18 17 sept. 15:38 .
	drwxr-xr-x 4 cthomasset users 90 17 sept. 15:34 ..
	drwx------ 2 cthomasset users 18 17 sept. 15:39 test

$ ls test
file

$ chmod -x test 
$ ls -ls
	total 0
	drwxr-xr-x 3 cthomasset users 18 17 sept. 15:38 .
	drwxr-xr-x 4 cthomasset users 90 17 sept. 15:34 ..
	drw------- 2 cthomasset users 18 17 sept. 15:39 test

$ touch file2
touch: impossible de faire un touch \'test/file2\': Permission non accordée

$ rm file
rm: impossible de supprimer \'test/file\': Permission non accordée

$ ls test
ls: impossible d\'accéder à \'test/file\': Permission non accordée
file

$ cd test
bash: cd: test/: Permission non accordée

$ cat test/file
cat: test/file: Permission non accordée
```

Les commandes qui necessitent l'execution ne fonctionne plus.

**5. **Dans un repertoire avec sticky bit:

- J'ai tout les droits sur mes créations
- Un autre utilisateur possede uniquement un droit de lecture

**6. ** Pour possisionner un sticky bit:

- `chmod +t <repertoire>`
- `chmod 1700 <repertoire>`

**7. ** La différence entre T et t: La capitale est présente si le droit d'exécution x caché n'est pas présent.

**8. ** La différence entre S et s: La capitale est présente si le droit d'exécution x caché n'est pas présent.

- SETUID se place sur le flag d'execution de l'utilisateur propriétaire.
- SETGID se place sur le flag d'execution du groupe propriétaire.

**9.** Pour le SUID: `chmod 4000 file`
Pour le SGID: `chmod 2000 file`

**10.**  Pour le SUID: `chmod u+s file`
Pour le SGID: `chmod g+s file`



#### 3.4 Envirronement de travail

**1. ** `set | more` pour afficher toutes les variables d’environement.

**2. ** `SHLVL` correspond au nombre maximum de shell qui peuvent être imbriquer l’un d’un l’autre. On peut tester un lançant la commande `bash` pour lancer un autre shell et en réafichant la variable `SHLVL`. 

**3.** Pour obtenir les informations de connexion: `id` ou `id | tr , “\n` pour un affichage en liste.

```shell
$ id | tr , "\n"
uid=54553(cthomasset) gid=100(users) groupes=100(users)
40664(Membres INSA)
60765(DIRCOM_TOUT_ETU_IDMAILING)
61323(GLPI-IFA)
61805(ETU-3_IFA_2018-2019)
61834(ETU-IFA_2018-2019)
61845(ETU-ING_3A_2018-2019)
61852(ETU-ING_2CYCLE_2018-2019)

```

On y voit le nom d’utilisateur `cthomasset` ainsi que le nom du groupe `users`. Les entiers associés correspondes au `userID` et au `groupID`. Ils permettent d’identifier l’utilisateur et le groupe. 



**4.** Pour obtenir la liste des shells: `cat /etc/shells`

```shell
$cat /etc/shells
/bin/ash
/bin/bash
/bin/csh
/bin/dash
/bin/false
/bin/ksh
/bin/ksh93
/bin/mksh
/bin/pdksh
/bin/sh
/bin/tcsh
/bin/true
/bin/zsh
/usr/bin/csh
/usr/bin/dash
/usr/bin/ksh
/usr/bin/ksh93
/usr/bin/mksh
/usr/bin/passwd
/usr/bin/pdksh
/usr/bin/bash
/usr/bin/tcsh
/usr/bin/zsh
/usr/bin/fish

```



**5.** Pour avoir le nombre de processus: `ps aux | wc -l` (`wc` -> word count, `wc -l` -> line count). Il y a 302 process qui tournent actuelement sur ma machine.

```shell
$ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.6  0.0 222372  9092 ?        Ss   17:44   0:14 /usr/lib/systemd/systemd --sw
root         2  0.0  0.0      0     0 ?        S    17:44   0:00 [kthreadd]
root         3  0.0  0.0      0     0 ?        S    17:44   0:00 [kworker/0:0]
root         4  0.0  0.0      0     0 ?        S<   17:44   0:00 [kworker/0:0H]
root         6  0.0  0.0      0     0 ?        S<   17:44   0:00 [mm_percpu_wq]
...
cthomas+  2169  0.3  0.1 655704 42892 ?        Ssl  17:46   0:07 /usr/lib/tracker-store
cthomas+  2171  0.0  0.1 734764 34588 tty2     Sl+  17:46   0:00 /usr/lib/deja-dup/deja-dup-mo
cthomas+  2174  0.0  0.0 399720 16568 tty2     Sl+  17:46   0:00 pk-update-icon
cthomas+  2179  0.0  0.0 416000  7352 ?        Sl   17:46   0:00 /usr/lib/gvfs/gvfsd-fuse /run
cthomas+  2182  0.0  0.0 272488  6696 ?        Sl   17:46   0:00 /usr/lib64/ibus/ibus-dconf
cthomas+  2183  0.1  0.1 434864 37448 ?        Sl   17:46   0:03 /usr/lib64/ibus/ibus-ui-gtk3
cthomas+  2186  0.0  0.1 538060 39440 tty2     Sl+  17:46   0:00 nm-applet
cthomas+  2191  0.0  0.0 343668 22720 ?        Sl   17:46   0:00 /usr/lib64/ibus/ibu
...

$ps aux | wc -l
302
```



**6. 7.** Pour avoir le nombre de process qui m’appartient: `ps -U cthomasset | wc -l` le flag `-U` permet de passer outre le fait que le nom d’utilisateur est trop long (charactère `+` à la fin). J’ai donc actuelement 80 processus executés qui tournent sur ma machine. 

```shell
$ps -U cthomasset
  PID TTY          TIME CMD
 2015 ?        00:00:00 systemd
 2016 ?        00:00:00 (sd-pam)
 2025 ?        00:00:00 gnome-keyring-d
 2031 tty2     00:00:00 gdm-x-session
 2033 tty2     00:01:34 X
 2057 ?        00:00:03 dbus-daemon
 2059 tty2     00:00:00 sh
 2117 ?        00:00:00 ssh-agent
 2122 tty2     00:00:00 xfce4-session
 2126 ?        00:00:00 xfconfd
 2132 tty2     00:00:09 xfwm4
 2136 tty2     00:00:02 xfce4-panel
 ...

$ps -U cthomasset | wc -l
80
```



**8.** Pour afficher un arbre des processus en utilisant uniquement les PIDs on utilise la commande suivante: `pstree -p`.

```shell
$pstree -p
systemd(1)─┬─ModemManager(1431)─┬─{ModemManager}(1443)
           │                    └─{ModemManager}(1447)
           ├─NetworkManager(1432)─┬─dhclient(2048)
           │                      ├─{NetworkManager}(1474)
           │                      └─{NetworkManager}(1479)
           ├─Thunar(2138)
           ├─accounts-daemon(1626)─┬─{accounts-daemon}(1627)
           │                       └─{accounts-daemon}(1629)
           ├─agetty(1672)
           ├─auditd(1390)───{auditd}(1391)
           ├─automount(2605)─┬─{automount}(2606)
           │                 ├─{automount}(2607)
           │                 └─{automount}(2610)
           ├─bluetoothd(1412)
           |
           ...
```



#### 3.5 Chaine de verification et outils de vérification valgrind

**1.** Création du fichier `demo.c` avec l’éditeur vim:

```c
// demo.c
#include <stdlib.h>

#define TAILLE 5

static void erreur(){
	int *pt = (int*) malloc(TAILLE * sizeof(int));
	pt[TAILLE] = -1;
}

int main(){
	erreur();
	return 0;
}
```



**2.** Pour obtenir le fichier `demo.i` on utilise la commande `g++ -E demo.c > demo.i` (on redirige le contenu de la sortie standard vers le fichier `demo.i`).

**3.** Pour obtenir le fichier `demo.s` on utilise la commande `g++ -S demo.c -o demo.s` (le flag `-o` spécifie le fichier de sortie).

```assembly
	.file	"demo.c"
	.text
	.type	_ZL6erreurv, @function
_ZL6erreurv:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$20, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$20, %rax
	movl	$-1, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	_ZL6erreurv, .-_ZL6erreurv
	.globl	main
	.type	main, @function
main:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	call	_ZL6erreurv
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 7.3.1 20180323 [gcc-7-branch revision 258812]"
	.section	.note.GNU-stack,"",@progbits
```

La ligne 46 (`	.size main, .-main`) correspond a l’appel de la fonction `main`.

**4.** L’option `-o` dans les commandes `gcc` ou `g++` permets de spécifier un fichier de sortie.

**5.** Pour terster la commande `valgrind` il faut d’abord créer l’éxécutable `demo`. On utilise la commande suivante: `gcc demo.c -o demo`. Ensuite on peut utiliser `valgrind` sur cet executable: 

```shell
$valgrind --leak-check=yes ./demo 
==7956== Memcheck, a memory error detector
==7956== Copyright (C) 2002-2017, and GNU GPL\'d, by Julian Seward et al.
==7956== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7956== Command: ./demo
==7956== 
==7956== Invalid write of size 4
==7956==    at 0x400525: erreur (in ./demo)
==7956==    by 0x400546: main (in ./demo)
==7956==  Address 0x51f4054 is 0 bytes after a block of size 20 alloc\'d
==7956==    at 0x4C2E08F: malloc (in /usr/lib64/valgrind/vgpreload_memcheck-amd64-linux.so)
==7956==    by 0x400518: erreur (in ./demo)
==7956==    by 0x400546: main (in ./demo)
==7956== 
==7956== 
==7956== HEAP SUMMARY:
==7956==     in use at exit: 20 bytes in 1 blocks
==7956==   total heap usage: 1 allocs, 0 frees, 20 bytes allocated
==7956== 
==7956== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
==7956==    at 0x4C2E08F: malloc (in /usr/lib64/valgrind/vgpreload_memcheck-amd64-linux.so)
==7956==    by 0x400518: erreur (in ./demo)
==7956==    by 0x400546: main (in ./demo)
==7956== 
==7956== LEAK SUMMARY:
==7956==    definitely lost: 20 bytes in 1 blocks
==7956==    indirectly lost: 0 bytes in 0 blocks
==7956==      possibly lost: 0 bytes in 0 blocks
==7956==    still reachable: 0 bytes in 0 blocks
==7956==         suppressed: 0 bytes in 0 blocks
==7956== 
==7956== For counts of detected and suppressed errors, rerun with: -v
==7956== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

```

> Note: pour des questions de lisibilité, j’ai remplacer `/home/cthomasset/cours-local/outils-et-langages-pour-le-developement-logiciel/TP/valgrind/demo` par `./demo`



On voit que `valgrind` a detecté 2 erreurs:

* **Fuite de mémoire**: 20 octets on été perdus. il correspondent à `TAILLE * sizeof(int) = 5 *4 = 20`. Ces 20 octets sont perdus car la zone reservée durant l’allocation dynamique de mémoire (`malloc`) n’a pas été libéré avec la function `free`. 
* **Accès à une zone interdite**: “écriture invalide d’une taille de 4 octets” elle est du au fait qu’on cherche à écrire dans une zone interdite en faisant `pt[TAILLE] = -1`. On déborde du tableau (index max: `TAILLE - 1`).

**6.** Correction du premier problème du programme démo avec la contrainte d’effectuer la libération de la zone allouée dans la fonction main.

```c
// demo.c
#include <stdlib.h>

#define TAILLE 5

int* erreur(){
	int *pt = (int*) malloc(TAILLE * sizeof(int));
	pt[TAILLE] = -1;	// On laisse temporairement cette erreur
	return pt;
}

int main(){
	int *pt = erreur();
	free(pt);				// Libération de l'espace alouée
	return 0;
}
```



**7.** On recrée un executable et on test à nouveau la commande `valgrind`. On obtient le retour suivant:

```shell
$valgrind --leak-check=yes ./demo 
==8984== Memcheck, a memory error detector
==8984== Copyright (C) 2002-2017, and GNU GPL\'d, by Julian Seward et al.
==8984== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8984== Command: ./demo
==8984== 
==8984== Invalid write of size 4
==8984==    at 0x400565: erreur (in ./demo)
==8984==    by 0x400589: main (in ./demo)
==8984==  Address 0x51f4054 is 0 bytes after a block of size 20 alloc\'d
==8984==    at 0x4C2E08F: malloc (in /usr/lib64/valgrind/vgpreload_memcheck-amd64-linux.so)
==8984==    by 0x400558: erreur (in ./demo)
==8984==    by 0x400589: main (in ./demo)
==8984== 
==8984== 
==8984== HEAP SUMMARY:
==8984==     in use at exit: 0 bytes in 0 blocks
==8984==   total heap usage: 1 allocs, 1 frees, 20 bytes allocated
==8984== 
==8984== All heap blocks were freed -- no leaks are possible
==8984== 
==8984== For counts of detected and suppressed errors, rerun with: -v
==8984== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

On observe que le problème de la libération de la zone allouée dynamiquement est bien corrigé “tout les blocks ont étés libérés”.



**8.** Création d’un script shell pour la compilation et l’édition des liens:

```sh
#!/bin/bash

if [ $# -eq 0 ]
  then
    echo "Veuillez spécifier le nom du fichier d'entré."
    echo "Exemple:   ./script.sh demo.c"
    exit
fi

inputfile=$1 # Récupération du fichier en entré
filename="${inputfile%.*}" # Extraction du nom du fichier (sans l'extension)

# Compilation
echo "Compilation du fichier ${inputfile} -> ${filename}.o"
gcc -c $inputfile -o ${filename}.o

# Edition des liens
echo "Reliage ${filename}.o -> ${filename}"
gcc -o $filename ${filename}.o -lm
```

Pour permettre une réutilisation de ce script j’ai permis à l’utilisateur de saisir le fichier à compiler/relier. Exemple d’utilisation:

```c
// test.c
#include <stdio.h>

int main(){
	printf("Ca marche!\r\n");
	return 0;
}
```

```shell
$ ./script.sh test.c
Compilation du fichier test.c -> test.o
Reliage test.o -> test

$ ./test
Ca marche!
```



**9.** Correction complete du programme `demo.c ` :

```c
// demo.c
#include <stdlib.h>

#define TAILLE 5

int* erreur(){
	int *pt = (int*) malloc(TAILLE * sizeof(int));
	pt[TAILLE - 1] = -1;	// Correction de l'écriture en zone interdite
	return pt;
}

int main(){
	int *pt = erreur();
	free(pt);				// Libération de l'espace alouée
	return 0;
}
```

Pour compiler et éditer les liens, on utilise la command `make` mais **sans makefile**, c’est à dire en utilisant les regles implicite de la commande `make` (disponnibles via la commande `make -p`).

```shell
$ make demo
cc     demo.c   -o demo
```



**10.**  Je commente l’instruction `return`, je recompile avec la commande `make` en utilisant les règles implicites, et je test le comportement de l’executable obtenue avec la `valgrind` :

```c
// demo.c
#include <stdlib.h>

#define TAILLE 5

int* erreur(){
	int *pt = (int*) malloc(TAILLE * sizeof(int));
	pt[TAILLE - 1] = -1;
	//return pt; 
}

int main(){
	int * pt = erreur();
	free(pt);
	return 0;
}
```

```shell
$make demo
cc    -c -o demo.o demo.c
cc   demo.o   -o demo

$ ./demo
*** Error in `./demo': free(): invalid pointer: 0x0000000002241274 ***
Abandon (core dumped)

$valgrind ./demo 
==4183== Memcheck, a memory error detector
==4183== Copyright (C) 2002-2017, and GNU GPL\'d, by Julian Seward et al.
==4183== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4183== Command: ./demo
==4183== 
==4183== Invalid free() / delete / delete[] / realloc()
==4183==    at 0x4C2F2BB: free (in /usr/lib64/valgrind/vgpreload_memcheck-amd64-linux.so)
==4183==    by 0x400596: main (in ./demo)
==4183==  Address 0x51f4050 is 16 bytes inside a block of size 20 alloc\'d
==4183==    at 0x4C2E08F: malloc (in /usr/lib64/valgrind/vgpreload_memcheck-amd64-linux.so)
==4183==    by 0x400558: erreur (in ./demo)
==4183==    by 0x400586: main (in ./demo)
==4183== 
==4183== 
==4183== HEAP SUMMARY:
==4183==     in use at exit: 20 bytes in 1 blocks
==4183==   total heap usage: 1 allocs, 1 frees, 20 bytes allocated
==4183== 
==4183== LEAK SUMMARY:
==4183==    definitely lost: 20 bytes in 1 blocks
==4183==    indirectly lost: 0 bytes in 0 blocks
==4183==      possibly lost: 0 bytes in 0 blocks
==4183==    still reachable: 0 bytes in 0 blocks
==4183==         suppressed: 0 bytes in 0 blocks
==4183== Rerun with --leak-check=full to see details of leaked memory
==4183== 
==4183== For counts of detected and suppressed errors, rerun with: -v
==4183== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```

La commande `free` sur le pointer non-initialisé à bien détecté par `valgrind`.



**11.**  On retest la même chose mais en construisant l’executable avec le script shell créé précedement. On obtient exactement le même résultat :

```shell
$rm demo

$ ./script.sh demo.c
Compilation du fichier demo.c -> demo.o
Reliage demo.o -> demo

$valgrind ./demo 
==4257== Memcheck, a memory error detector
==4257== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4257== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4257== Command: ./demo
==4257== 
==4257== Invalid free() / delete / delete[] / realloc()
==4257==    at 0x4C2F2BB: free (in /usr/lib64/valgrind/vgpreload_memcheck-amd64-linux.so)
==4257==    by 0x4005A6: main (in ./demo)
==4257==  Address 0x553f050 is 16 bytes inside a block of size 20 alloc'd
==4257==    at 0x4C2E08F: malloc (in /usr/lib64/valgrind/vgpreload_memcheck-amd64-linux.so)
==4257==    by 0x400568: erreur (in ./demo)
==4257==    by 0x400596: main (in ./demo)
==4257== 
==4257== 
==4257== HEAP SUMMARY:
==4257==     in use at exit: 20 bytes in 1 blocks
==4257==   total heap usage: 1 allocs, 1 frees, 20 bytes allocated
==4257== 
==4257== LEAK SUMMARY:
==4257==    definitely lost: 20 bytes in 1 blocks
==4257==    indirectly lost: 0 bytes in 0 blocks
==4257==      possibly lost: 0 bytes in 0 blocks
==4257==    still reachable: 0 bytes in 0 blocks
==4257==         suppressed: 0 bytes in 0 blocks
==4257== Rerun with --leak-check=full to see details of leaked memory
==4257== 
==4257== For counts of detected and suppressed errors, rerun with: -v
==4257== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```



**12.** Dans le but d’obtenir une erreur suite à l’absence du `return` de la function `erreur()` j’ai modifié mon script de compilation pour qu’il intègre les flags `-Wall -Werror -pedantic`. Ils donnent les informations suivantes: active tout les *warning*, retourne une erreur pour chaque *warning*, et retourne une erreur si le code ne se plie pas a la norme `ansi`.

```sh
#!/bin/bash

if [ $# -eq 0 ]
  then
    echo "Veuillez spécifier le nom du fichier d'entré."
    echo "Exemple:   ./script.sh demo.c"
    exit
fi

inputfile=$1 # Récupération du fichier en entré
filename="${inputfile%.*}" # Extraction du nom du fichier

echo "Compilation du fichier ${inputfile} -> ${filename}.o"
gcc -Werror -Wall -pedantic -c $inputfile -o ${filename}.o
echo "Reliage ${filename}.o -> ${filename}"
gcc -o $filename ${filename}.o -lm
```

```shell
$./script.sh demo.c
Compilation du fichier demo.c -> demo.o
demo.c: Dans la fonction « erreur »:
demo.c:9:1: error: le contrôle a atteint la fin d\'une fonction non « void » [-Werror=return-type]
 }
 ^
cc1 : tous les avertissements sont traités comme des erreurs

```

Le script a bien détecté l’absence du `return`.



**13.** Pour que la commande `make` retourne une erreur à la compilation il faudrait ajouter les valeurs `-Wall -Werror -pedantic` a la variable implicit `CFLAGS` (qui correspond aux flags du compilateur `C`) et comme le dit la [documentation](https://www.gnu.org/software/make/manual/html_node/Overriding.html), le moyen serait le suivant ` make CFLAGS='-Wall -Werror -pedantic' demo`. Mais ça ne fonctionne pas.