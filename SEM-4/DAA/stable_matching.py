man = {
    "m1": ["w2", "w1", "w3"],
    "m2": ["w1", "w3", "w2"],
    "m3": ["w3", "w2", "w1"]
}

women = {
    "w1": ["m1", "m3", "m2"],
    "w2": ["m3", "m1", "m2"],
    "w3": ["m2", "m1", "m3"]
}

free =[x for x in man.keys()]
prop={x:[] for x in man.keys()}
eng={x:0 for x in women.keys()}

def match(man,women):
  while free:
    m=free.pop()
    mp=man[m]

    for w in mp:
      if w not in prop[m]:
        prop[m].append(w)

        if not eng[w]:
          eng[w]=m
          break
        else:
          cp=m
          wp=women[w]

          if wp.index(cp)>wp.index(m):
            eng[w]=m
            free.append(cp)
            break


  print(eng)
match(man,women)