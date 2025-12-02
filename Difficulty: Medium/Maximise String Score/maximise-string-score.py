class Solution:
    def maxScore(self, s, jumps):
        from collections import defaultdict
        
        n = len(s)
        if n == 0:
            return 0
        
        psums = [0] * (n + 1)
        for i, e in enumerate(s):
            psums[i+1] = ord(e) + psums[i]
        
        char_prefix = {}
        unique_chars = set(s)
        char_ords = {c: ord(c) for c in unique_chars}
        for char in unique_chars:
            arr = [0] * (n + 1)
            char_ord = char_ords[char]
            for i in range(n):
                arr[i+1] = arr[i] + (1 if ord(s[i]) == char_ord else 0)
            char_prefix[char] = arr
        
        jump_map = defaultdict(set)
        for frm, to in jumps:
            jump_map[frm].add(to)
        
        dp = [0] * (n + 1)
        best_val = defaultdict(lambda: float('-inf'))
        
        for pos in range(n - 1, -1, -1):
            char = s[pos]
            char_ord = char_ords[char]
            max_score = 0
            
            chars_to_check = {char}
            if char in jump_map:
                chars_to_check.update(jump_map[char])
            
            base_sum = psums[pos]
            for target_char in chars_to_check:
                target_ord = char_ords[target_char]
                target_prefix = char_prefix[target_char]
                base_count = target_prefix[pos]
                
                if best_val[target_char] != float('-inf'):
                    score = best_val[target_char] + base_count * target_ord - base_sum
                    if score > max_score:
                        max_score = score
            
            dp[pos] = max_score
            
            char_prefix_arr = char_prefix[char]
            val = psums[pos+1] + dp[pos] - char_prefix_arr[pos+1] * char_ord
            if val > best_val[char]:
                best_val[char] = val
        
        return dp[0]