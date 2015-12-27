function placing ()
  print(nbPalcePerso())
  placePerso(7,2,1);
end


function main ()
  -- life = getLifePerso( getCoodPerso() )
  -- life = getLifePerso( 1,6  )
  -- print(getCoodPerso())
  print(getNearestEnemy( getCoodPerso() ))

  x,y =getCoodPerso()
  -- print(getPathLength( x,y , 9,0 ))

  -- content = getCellContent( 3,2 )
  -- print(content)

  print("is enemy", isAlly(0,6))

  print("perso : ", getClass( getCoodPerso()))
  print("pa: ", getTotalPM( getCoodPerso()))
end
