
function sum (param1, param2)
  result = param1 + param2
  return result
end

function placing ()
  print(nbPalcePerso())
  placePerso(2,6,1);
end


function main ()
  -- life = getLifePerso( getCood() )
  -- life = getLifePerso( 1,6  )
  -- print(getCood())
  print("test 1")
  x,y =getCood()
  print(x,y)

  print(getNearestEnemy())

  print("pa need",getPathLength( 9,0 ))

  -- content = getCellContent( 3,2 )
  -- print(content)

  print("is enemy", isEnemy(0,6))

  print("perso : ", getClass( getCood()))
  print("pa: ", getTotalPM( getCood()))
end
