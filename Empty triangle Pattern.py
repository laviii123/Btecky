
ph = 5  # height 
ps = ph - 1  # space 
inc = 1 

# Top Pyramid 
for x in range(0, ph): 
    # Broad Space 
    for s in range(0, ph - 1): 
        print(" ", end="") 
    for s in range(ps, x - 1, -1): 
        print(" ", end="") 

    for y in range(0, x + 1): 
        print("* ", end="") 
    print() 

# Bottom Pyramids 
for x in range(0, ph): 
    for y in range(ps, x, -1): 
        print(" ", end="") 
    for z in range(0, x + 1): 
        print("* ", end="") 

    for y in range(ph + ph - 2, inc - 1, -1): 
        print(" ", end="") 
    for z in range(0, x + 1): 
        print("* ", end="") 

    inc += 2 
    print()


'''
for n=3
      *
     * *
    * * *
   *     *
  * *   * *
 * * * * * *
 '''
