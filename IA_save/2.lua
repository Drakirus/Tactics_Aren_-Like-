function placing ()
  print(nbPlacePerso())
  placePerso(7,9,1);
  -- placePerso(1,2,1);
end


function main ()
  print("test 2")
  x,y =getCood()
  print(x,y)

  -- life = getLifePerso( getCood() )
  -- life = getLifePerso( 1,6  )
  -- print(getCood())
  print(getNearestEnemy())

  print("pa need",getPathLength( 9,0 ))

  -- content = getCellContent( 3,2 )
  -- print(content)

  print("is ally", isEnemy(0,6))

  print("perso : ", getClass( getCood()))
  print("pa: ", getTotalPA( getCood()))
  i , j = getNearestEnemy()
  -- moveToward( i , j , 3)
  moveAway( i , j , 3)
end
