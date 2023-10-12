class DNA {
  PVector[] genes=new PVector[lifespan];

  DNA() {
    for (int i=0; i<lifespan; i++)  genes[i]=PVector.random2D().setMag(maxforce);
  }

  void mutation() {
    for (int i=0; i<lifespan; i++) {
      if (random(1)<mutationRate) {
        genes[i]=PVector.random2D().setMag(maxforce);
      }
    }
  }

  DNA crossingover(DNA dn) {
    DNA d=new DNA();
    float mid=random(lifespan);
    for (int i=0; i<lifespan; i++) {
      if (i<mid) {
        d.genes[i]=genes[i];//this parent
      } else {
        d.genes[i]=dn.genes[i];
      }
    }
    return d;
  }
}
