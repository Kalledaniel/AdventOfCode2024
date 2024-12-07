from operator import mul; import re
print(eval('+'.join(re.findall(r'mul\(\d+,\d+\)', open('input.txt').read()))))
d = open('input.txt').read()
for s in d, re.sub(r'don\'t\(\)[\s\S]*?(do\(\)|$)', '', d):
    print(eval('+'.join(re.findall(r'mul\(\d+,\d+\)', s))))


175700056
71668682
8211015
