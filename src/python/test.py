import model

#globals
ended = False
compteur = 0

#stratégie python
def strat(model):
	model.affiche()
'''
	#case_avant = controller.getCaseAvant()
	if case_avant == "herbe":
		return "avance"
	else:
		global compteur
		compteur += 1
		if compteur > 10:
			global ended
			ended = True
		return "tourne_gauche"
'''
#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;


#pour mémoire
def func(a) :
	if a == "herbe":
		x = "vas y roule"
	else:
		x = "n'y va pas !"
	return (x)
