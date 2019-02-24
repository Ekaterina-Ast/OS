#import math
text_file=[] #Список - номера полученных пакетов

#Открываем файл, считываем данные в text_file
def open_file(data_txt):
    try:
        with open(data_txt) as file:
             for i in file:
               text_file.append(int(i))
    except IOError:
       print ("Could not open file! Please close Excel!")


#Удаление дубликатов пакетов
def remove_duplicates(data_number):
    no_duplic_data=[]
    for number in data_number:
        if len(no_duplic_data) > 0:
           if number != no_duplic_data[-1]:
               no_duplic_data.append(number)
        else:
            no_duplic_data.append(number)
    return no_duplic_data

#проверка на полноту передачи сообщения
def isFull_message(data_mess):
    return all((data_mess[i+1]-data_mess[i])==1 for i in range(len(data_mess)-1))
  
# определение отсутствующих пакетов
def missing_pack(data_mess):
    curr_pack_number=data_mess[0]
    data_numb_index = 0
    missing_pack=[]
    for i in range(data_mess[-1]- data_mess[0]):
        if (data_mess[data_numb_index] - curr_pack_number) >= 1:
            missing_pack.append(curr_pack_number)
            curr_pack_number +=1 
        else:
            curr_pack_number +=1 
            data_numb_index +=1
    return missing_pack
#Определим полностью ли мы получили сообщение из пакетов
def func_full_pack(text_file_list):
    if isFull_message(text_file_list):
        print ("Сообщение {} - {} получено полностью".format(text_file_list[0], text_file_list[-1]))
    else:
        missing_packet = missing_pack(text_file_list)
        print ("Сообщение {} - {} не хватает пакетов ".format(text_file_list[0], text_file_list[-1]),end = ':')
        print (*missing_packet, sep=", ")


#Открытие файла
open_file('data_checker.txt')
for data_packet in range(len(text_file)):
    pack_check = text_file[0:data_packet+1]
    #Сортируем по возрастанию
    pack_check = sorted(pack_check)
    #Удалим дублирующиеся пакеты
    pack_check = remove_duplicates(pack_check)
    func_full_pack(pack_check)

