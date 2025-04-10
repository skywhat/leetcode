class Solution:
    def compress(self, chars: List[str]) -> int:
        start = i = 0
        while i< len(chars):
            counter = 1
            while i + counter < len(chars) and chars[i] == chars[i+counter]:
                counter +=1
            chars[start] = chars[i]
            start +=1
            i += counter
            counter_str_list = list(str(counter))
            if counter > 1:
                chars[start:start+len(counter_str_list)] = counter_str_list
                start += len(counter_str_list)
        return start
            