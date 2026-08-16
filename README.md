

### En Mac / Linux (bash/zsh)

**Compilar:**
```bash
g++ -std=c++17 -O2 -Werror -Wall -Wextra -Wpedantic -Wnull-dereference -Wlogical-op -Wduplicated-cond -Wshadow -Wconversion -o programa main.cpp
```

**Ejecutar con input a mano:**
```bash
./programa
```

**Ejecutar con input desde archivo:**
```bash
cat in.txt | ./programa > out.txt
# o equivalentemente:
./programa < in.txt > out.txt
```

**Ejecutar con input inline (sin archivo):**
```bash
echo "5" | ./programa
echo "input1 input2 input3" | ./programa
```

---

### En Windows (PowerShell)

**Compilar** (desde PowerShell, requiere g++ instalado vía MinGW o similar):
```powershell
g++ -std=c++17 -O2 -Werror -Wall -Wextra -Wpedantic -Wnull-dereference -Wlogical-op -Wduplicated-cond -Wshadow -Wconversion -o programa.exe main.cpp
```

**Ejecutar con input a mano:**
```powershell
.\programa.exe
```

**Ejecutar con input desde archivo:**
```powershell
Get-Content in.txt | .\programa.exe > out.txt
# o equivalentemente:
.\programa.exe < in.txt > out.txt
```

**Ejecutar con input inline (sin archivo):**
```powershell
echo "5" | .\programa.exe
```

---

### Compilar con Ctrl+Shift+B en VS Code y correr de forma simple 

Con VS Code, `Ctrl+Shift+B` ejecuta la tarea de compilación configurada en `.vscode/tasks.json`. 

correr luego

./main < in.txt > out.txt 

en windows, darle run  con vscode y luego desde bash

./main.exe < in.txt > out.txt 


