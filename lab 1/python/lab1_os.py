from ctypes import windll, byref, Structure, Array, wintypes
#описываем структуру ULONGLONG в виде класса,с помощью типов данных Windows,
#описанных в ctypes.wintypes
class ULONGLONG(Structure):
    _fields_ = [("RAM", wintypes.ULONG),]
#создаём переменную, являющуюся экзкмпляром класса ULONGLONG 
si = ULONGLONG()
#загружаем динамическую библиотеку kernel32.dll
kernel32 = windll.kernel32
#вызываем функцию GetPhysicallyInstalledSystemMemory,передавая ей переменную si по ссылке 
kernel32.GetPhysicallyInstalledSystemMemory(byref(si))
#выводим содержимое полей структуры ULONGLONG 
print("RAM =",si.RAM,"kB")
