:- module(hw5, [catomic_number/2, ion/2, molecule/2]).
:- [catoms].

% Elements with 4 valence electrons is assumed to form only cations
anion(NAME, CHARGE) :-
	catom(NAME, _, _, ELECTRON_LIST),
	last(ELECTRON_LIST, VALENCE_ELECTRONS),
	VALENCE_ELECTRONS > 4,
	CHARGE is VALENCE_ELECTRONS-8.
	
cation(NAME, CHARGE) :-
	catom(NAME, _, _, ELECTRON_LIST),
	last(ELECTRON_LIST, VALENCE_ELECTRONS),
	VALENCE_ELECTRONS =< 4,
	CHARGE is VALENCE_ELECTRONS.

ion(NAME, CHARGE) :- cation(NAME, CHARGE); anion(NAME, CHARGE).
	
catomic_number(NAME, CATOMIC_NUMBER) :-
	catom(NAME, _, _, ELECTRON_LIST),
	sum_list(ELECTRON_LIST, CATOMIC_NUMBER).


% find an atom list sorted by atomic number
molecule(CATOM_LIST, TOTAL_CATOMIC_NUMBER) :-
	ion(NAME, CHARGE),
	catomic_number(NAME, CATOMIC_NUMBER),
	RCN is TOTAL_CATOMIC_NUMBER - CATOMIC_NUMBER,
	molecule_former([NAME], CHARGE, RCN, CATOM_LIST).

molecule_former(CATOM_LIST, 0, 0, CATOM_LIST).
molecule_former([NAME_1 | OTHER_ATOMS], CURRENT_CHARGE_SUM, CURRENT_RCN, CATOM_LIST) :-
	ion(NAME_2, CHARGE),
	catomic_number(NAME_1, CN_1),
	catomic_number(NAME_2, CN_2),
	CN_2 =< CN_1,
	NEW_RCN is CURRENT_RCN - CN_2,
	NEW_RCN >= 0,
	NEW_CHARGE_SUM is CURRENT_CHARGE_SUM + CHARGE,
	molecule_former([NAME_2 | [NAME_1 | OTHER_ATOMS]], NEW_CHARGE_SUM, NEW_RCN, CATOM_LIST).