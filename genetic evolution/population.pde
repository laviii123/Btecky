

class Population {
  Rocket[] rockets=new Rocket[population];
  ArrayList<Rocket> matingPool=new ArrayList<Rocket>();

  Population(PVector posRocket) {
    for (int i=0; i<population; i++)  rockets[i]=new Rocket(posRocket);
  }

  void run() {
    boolean alldead_=true;
    for (Rocket rocket : rockets) {
      rocket.update();
      rocket.display();
      if (!rocket.reached && !rocket.crashed)  alldead_=false;

      for (Obstacle obs : obstacles) obs.checkCollision(rocket);
    }
    age++;
    alldead=alldead_;
  }

  void selection(PVector posRocket) {
    Rocket[] newRockets=new Rocket[population];

    for (int i=0; i<population; i++) {
      Rocket parentA=matingPool.get(int(random(matingPool.size())));
      Rocket parentB=matingPool.get(int(random(matingPool.size())));
      
      if(parentA.fitness>stat && parentB.fitness>stat){//checking if the parents are above avergae beacause genetic evolution is slow
        newRockets[i]=parentA.crossover(parentB, posRocket);//main genetic algo step1
        newRockets[i].dna.mutation();//main genetic algo step2
      }else{
        i--;
      }
      
    }

    rockets=newRockets;
  }

  float evaluate() {
    float avg_fitness=0.0, max_fitness=0.0;

    //calculate fitness
    for (Rocket r : rockets) {
      r.calcFitness();

      max_fitness=max(max_fitness, r.fitness);
      avg_fitness+=r.fitness;
    }
    avg_fitness/=population;


    //mating pool arraylist
    for (Rocket r : rockets) {
      float n = r.fitness/max_fitness;//normalizing fitness
      n*=100;
      for (int j=0; j<n; j++) {
        matingPool.add(r);
      }
    }
    return avg_fitness;
  }
}
