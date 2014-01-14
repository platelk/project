################################################################################
#                                                                              #
#                       Makefile in 3_programmer_avec_ocaml                    #
#                       For Epitech's λ Knowledge Unit                         #
#                       Made by: David GIRON                                   #
#                                                                              #
################################################################################


all:
	@make -C ./1_interface
	@make -C ./2_abstracts_types
	@make -C ./3_langage_de_modules

documentation:
	@make -C ./1_interface documentation
	@make -C ./2_abstracts_types documentation
	@make -C ./3_langage_de_modules documentation

doc:	documentation

doc_clean:
	@make -C ./1_interface doc_clean
	@make -C ./2_abstracts_types doc_clean
	@make -C ./3_langage_de_modules doc_clean

doc_re:	doc_clean doc

clean:
	@make -C ./1_interface clean
	@make -C ./2_abstracts_types clean
	@make -C ./3_langage_de_modules clean

fclean:
	@make -C ./1_interface fclean
	@make -C ./2_abstracts_types fclean
	@make -C ./3_langage_de_modules fclean

tar:	fclean
	tar -cvzf 3_programmer_avec_ocaml.tar.gz *


################################################################################
