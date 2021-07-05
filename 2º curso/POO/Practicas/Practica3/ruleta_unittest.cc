#include "ruleta.h"
#include "crupier.h"
#include "jugador.h"
#include "gtest/gtest.h"
#include <list>
#include <vector>

TEST(Ruleta, Constructor){
  Crupier c("dni1", "codigo1");
  Ruleta r(c);

  EXPECT_EQ("dni1", r.getCrupier().getDNI());
  EXPECT_EQ("codigo1", r.getCrupier().getCodigo());
  EXPECT_EQ(-1, r.getBola());
  EXPECT_EQ(1000000, r.getBanca());
  EXPECT_TRUE(r.getJugadores().empty());
}

TEST(Ruleta, getsetBola){
  Crupier c("dni1", "codigo1");
  Ruleta r(c);

  for (int i = 0; i < 37; i++){
    EXPECT_TRUE(r.setBola(i));
    EXPECT_EQ(i, r.getBola());
  }
  EXPECT_FALSE(r.setBola(40));
  EXPECT_EQ(36, r.getBola());
  EXPECT_FALSE(r.setBola(-1));
  EXPECT_EQ(36, r.getBola());
}

TEST(Ruleta, getsetBanca){
  Crupier c("dni1", "codigo1");
  Ruleta r(c);

  EXPECT_TRUE(r.setBanca(5));
  EXPECT_EQ(5, r.getBanca());
  EXPECT_FALSE(r.setBanca(-1));
  EXPECT_EQ(5, r.getBanca());
}

TEST(Ruleta, getsetCrupier){
  Crupier c("dni1", "codigo1");
  Crupier d("dni2", "codigo2");
  Ruleta r(c);

  r.setCrupier(d);
  EXPECT_EQ("dni2", r.getCrupier().getDNI());
  EXPECT_EQ("codigo2", r.getCrupier().getCodigo());
}

TEST(Ruleta, addgetJugadores){
  Crupier c("dni1", "codigo1");
  Ruleta r(c);

  std::vector<Jugador> j;
  for (int i = 0; i < 10; i++) {
    j.push_back(Jugador("dni" + i, "code" + i));
    EXPECT_TRUE(r.addJugador(j[i]));
  }

  std::list<Jugador> jugadores;
  jugadores = r.getJugadores();

  int count=0;
  for (Jugador j : jugadores) {
    EXPECT_EQ("dni" + count, j.getDNI());
    EXPECT_EQ("code" + count, j.getCodigo());
    count++;
  }
}

