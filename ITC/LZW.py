import math
from collections import defaultdict
#print("Enter String")

d = defaultdict(object)
# def DecimalToBinary(num): 
      
#     if num > 1: 
#         DecimalToBinary(num // 2) 
#     print(num % 2, end = '\n') 
    
    
str = input('Enter String ')
print("\nLocation\t\tPhrase\t\tCodeWord",end='\n')
def filtCheck(a_dictionary,filter_string):
    for key, value in a_dictionary.items():
        # print(key,value)
        if filter_string == value['phrase']:
            return value['loc']
#print(len(str))
#print(math.log2(len(str)))
make_sub_string=''
d[0]={'loc':'0b1',
        'phrase': str[0],
        'codeword': ''}

def add_new_char(get_object,char_to_be_added):
    get_object['phrase']+=char_to_be_added
    


for i in range(len(str)):
    if i<len(str)-1:
        make_sub_string+=str[i+1]
    found=False
    for key,value in d.items():
        # print(key,value)
        if d[key]['phrase']==make_sub_string:
            found=True
            pass
        # if item['phrase']==make_sub_string:
        #     pass
        else:
            # setattr(d[item+1], 'phrase', make_sub_string)
            l=key+1
    if not found:
        d[l] = {'phrase':make_sub_string }
        newDict ={'loc':bin(l+1)}
        d[l].update(newDict)
        
        make_sub_string=''

    # return filtered_dict
            
            
#default dictionary can not be manipulated (new key value addition ) during iteration
# print(int(math.log2(len(d)))+1)
for item in d:
        # print(d[item]['phrase'],end='\n')
            if len(d[item]['loc'][2:])!=(int(math.log2(len(d)))+1):
                d[item]['loc']="0"*(int(math.log2(len(d)))+1-len(d[item]['loc'][2:]))+d[item]['loc'][2:]
                # d[item]['loc']="0"*(int(math.log2(len(d)))+1-len(d[item]['loc'][2:]))+d[item]['loc'][2:]
            if d[item]['loc'][1]=='b':
                d[item]['loc']=d[item]['loc'][2:]
                
            
for itema in d:
    i=0
    if len(d[itema]['phrase'])==1:
        d[itema]['codeword']="0"*(int(math.log2(len(d)))+1)+d[itema]['phrase']
    else:
        # d[itema]['codeword']=d[itema]['loc']+d[itema]['phrase'][-1] 
        # val = filter(filtCheck(d[itema]['phrase'][:len(d[itema]['phrase'])-1]), d)
        alll=filtCheck(d,d[itema]['phrase'][:len(d[itema]['phrase'])-1])
        if d[itema]['phrase']!="":
            d[itema]['codeword']=alll+d[itema]['phrase'][-1]
        i=i+1
        # print(alll)
        # d[itema]['codeword']=val['loc']+d[itema]['phrase'][-1] 
        
        
for iteaam in d:    
    
    if d[iteaam]['phrase'] != '' :
        # print("{}       |       {}      |       {}".format(d[iteaam]['loc'],d[iteaam]['phrase'],d[iteaam]['codeword']),end='\n')
        print("{}\t\t\t|{}\t\t\t|{}".format(d[iteaam]['loc'],d[iteaam]['phrase'],d[iteaam]['codeword']),end='\n')
        
# for i in range(int(math.log2(len(str)))):
#    DecimalToBinary(i)