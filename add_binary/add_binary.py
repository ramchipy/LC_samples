def add_binary(bin1, bin2):
    carry = 0
    i = 0
    result = ""
    while (i < max(len(bin1), len(bin2))) or carry != 0:
        sum = carry
        
        if i < len(bin1):
            sum += int(bin1[len(bin1)-i-1])
        
        if i < len(bin2):
            sum += int(bin2[len(bin2)-i-1])
        
        carry = sum // 2
        sum = sum % 2
        result = "{}".format(sum) + result
        i += 1
    return result

for bin1, bin2 in [["00", "00"], ["01", "00"], ["01", "01"], ["11", "01"], ["110", "010"], ["01", "0000100"]]:
    print("{} + {} = {}".format(bin1, bin2, add_binary(bin1, bin2)))