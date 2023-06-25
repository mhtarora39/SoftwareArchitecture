

def build_encodings(str,num_stack):

    tmp_res  = ""
    for i in range(len(str)):
        chr = str[i]
        if chr >= '0' and chr <= '9':
           num = int(chr)
           num_stack.append(num)

        elif chr == '[':
            j = i+1
            tmp_res = tmp_res + build_encodings(str[j:],num_stack)
            #print(prev_res)
        
        elif chr == ']':
            new_num = num_stack.pop()
            print(new_num,"->>>>",tmp_res)
            return (new_num -1) * (tmp_res)
        
        else:
            tmp_res = tmp_res + chr
    return tmp_res

print(build_encodings("4[s2[a]]2[c]",[2]))

    
        






  