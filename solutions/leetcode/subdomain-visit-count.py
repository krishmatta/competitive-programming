class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        ret = {}
        for x in cpdomains:
            rep, d = x.split()
            rep = int(rep)
            d = d.split(".")[::-1]
            curr = ""
            for x in d:
                if curr != "":
                    curr = "." + curr
                curr = x + curr
                if curr not in ret:
                    ret[curr] = 0
                ret[curr] += rep
        ret = [f"{v} {k}" for k, v in ret.items()]
        return ret
