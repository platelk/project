##
## Makefile for bomberman in /home/leprov_a//project/tek2/bomberman/dev
##
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
##
## Started on  Mon Apr 29 10:42:09 2013 alexis leprovost
##

SERVER		=	./bin/server
CLIENT		=	./bin/client
MAIN		=	bomberman

EXEC		=	$(SERVER) $(CLIENT) $(MAIN)

SRC_DIR		=	./src/
INC_DIR		=	./inc/
GDL_DIR		=	./lib/gdl/
TINY_DIR	=	./lib/tinyxml/
FMOD_DIR	=	./lib/fmod/
FREEIMAGE_DIR	=	./lib/freeimage/
BIN_DIR		=	./bin/

SRC		=	$(SRC_DIR)Client/Core.cpp \

SRC		+=	$(SRC_DIR)Client/Screenshot/Screenshot.cpp \

SRC		+=	$(SRC_DIR)Client/Controller/Input.cpp \
			$(SRC_DIR)Client/Controller/InputJoystick.cpp \
			$(SRC_DIR)Client/Controller/Controller.cpp \

SRC		+=	$(SRC_DIR)Client/Event/Event.cpp \
			$(SRC_DIR)Client/Event/MouseEvent.cpp \
			$(SRC_DIR)Client/Event/KeyboardEvent.cpp \
			$(SRC_DIR)Client/Event/TrameEvent.cpp \
			$(SRC_DIR)Client/Event/JoystickEvent.cpp \
			$(SRC_DIR)Client/Event/CameraEvent.cpp \
			$(SRC_DIR)Client/Event/UpdateEvent.cpp \
			$(SRC_DIR)Client/Event/EventListener.cpp \

SRC		+=	$(SRC_DIR)Client/Interface/Widget.cpp \
			$(SRC_DIR)Client/Interface/Stage.cpp \
			$(SRC_DIR)Client/Interface/Interface.cpp \
			$(SRC_DIR)Client/Interface/Image.cpp \
			$(SRC_DIR)Client/Interface/Ui.cpp \
			$(SRC_DIR)Client/Interface/Text.cpp \
			$(SRC_DIR)Client/Interface/TextBox.cpp \
			$(SRC_DIR)Client/Interface/KeyBox.cpp \
			$(SRC_DIR)Client/Interface/NumBox.cpp \
			$(SRC_DIR)Client/Interface/SoundBox.cpp \
			$(SRC_DIR)Client/Interface/ProfileBox.cpp \
			$(SRC_DIR)Client/Interface/ScoreBox.cpp \
			$(SRC_DIR)Client/Interface/MapBox.cpp \
			$(SRC_DIR)Client/Interface/TextManager.cpp \
			$(SRC_DIR)Client/Interface/Button.cpp \
			$(SRC_DIR)Client/Interface/ButtonManager.cpp \
			$(SRC_DIR)Client/Interface/CharacterBox.cpp \
			$(SRC_DIR)Client/Interface/Camera.cpp \
			$(SRC_DIR)Client/Interface/LogicTree.cpp \
			$(SRC_DIR)Client/Interface/Screener.cpp \
			$(SRC_DIR)Client/Interface/GameManager.cpp \

SRC		+=	$(SRC_DIR)Client/Sound/Sound.cpp \
			$(SRC_DIR)Client/Sound/SoundManager.cpp \

SRC		+=	$(TINY_DIR)src/tinyxml2.cpp \
			$(SRC_DIR)XML/OverTiny.cpp \
			$(SRC_DIR)XML/Achievment.cpp \
			$(SRC_DIR)XML/ParsAchievments.cpp \
			$(SRC_DIR)XML/Level.cpp \
			$(SRC_DIR)XML/ParsLevels.cpp \
			$(SRC_DIR)XML/ParsPersos.cpp \
			$(SRC_DIR)XML/Profile.cpp \
			$(SRC_DIR)XML/ParsProfiles.cpp \
			$(SRC_DIR)XML/Map.cpp \
			$(SRC_DIR)XML/ParsMaps.cpp \
			$(SRC_DIR)XML/ParsSaves.cpp \
			$(SRC_DIR)XML/Score.cpp \
			$(SRC_DIR)XML/ParsScores.cpp \
			$(SRC_DIR)XML/ConfXML.cpp \

SRC		+=	$(SRC_DIR)Client/Trigger/Trigger.cpp \

SRC		+=	$(SRC_DIR)Client/Network/ClientNetwork.cpp \
			$(SRC_DIR)Client/Network/ServerBroadcast.cpp \
			$(SRC_DIR)Client/Network/ListServer.cpp \
			$(SRC_DIR)Client/Network/Sender.cpp \
			$(SRC_DIR)Client/Network/Listener.cpp \
			$(SRC_DIR)Client/Network/AUDPMultiCast.cpp \

SRC		+=	$(SRC_DIR)Tools/Point.cpp \
			$(SRC_DIR)Tools/Timer.cpp \
			$(SRC_DIR)Tools/Vector.cpp \
			$(SRC_DIR)Tools/Vector.cpp \
			$(SRC_DIR)Tools/Noise/Perlin.cpp \
			$(SRC_DIR)Tools/MapGenerator.cpp \
			$(SRC_DIR)Tools/Color.cpp \
			$(SRC_DIR)Tools/Factory.cpp \
			$(SRC_DIR)Tools/utils.cpp \
			$(SRC_DIR)Tools/MapGenerator.cpp \
			$(SRC_DIR)Tools/Noise/Perlin.cpp \

SRC		+=	$(SRC_DIR)Thread/Mutex.cpp \
			$(SRC_DIR)Thread/Cond.cpp \
			$(SRC_DIR)Thread/LockScope.cpp \

SRC		+=	$(SRC_DIR)Daemon/Core/Event/EventTree.cpp \
			$(SRC_DIR)Daemon/Core/Event/Listener.cpp \

SRC		+=	$(SRC_DIR)Daemon/Core/Trame/Trame.cpp \

SRC		+=	$(SRC_DIR)Daemon/Core/Core.cpp \

SRC		+=	$(SRC_DIR)Daemon/Core/Entity/AEntity.cpp \

SRC		+=	$(SRC_DIR)Daemon/Core/GameObject/GameObject.cpp \

SRC		+=	$(SRC_DIR)Daemon/Core/Component/Life.cpp \
			$(SRC_DIR)Daemon/Core/Component/Explose.cpp \
			$(SRC_DIR)Daemon/Core/Component/Position.cpp \
			$(SRC_DIR)Daemon/Core/Component/Move.cpp \
			$(SRC_DIR)Daemon/Core/Component/ThrowBomb.cpp \
			$(SRC_DIR)Daemon/Core/Component/Colider.cpp \
			$(SRC_DIR)Daemon/Core/Component/Network.cpp \
			$(SRC_DIR)Daemon/Core/Component/EndGame.cpp \
			$(SRC_DIR)Daemon/Core/Component/DeleteBuff.cpp \
			$(SRC_DIR)Daemon/Core/Component/NewPlayer.cpp \
			$(SRC_DIR)Daemon/Core/Component/Render.cpp \
			$(SRC_DIR)Daemon/Core/Component/PlayerRender.cpp \
			$(SRC_DIR)Daemon/Core/Component/GroundRender.cpp \
			$(SRC_DIR)Daemon/Core/Component/AComponent.cpp \
			$(SRC_DIR)Daemon/Core/Component/CreateGameObject.cpp \
			$(SRC_DIR)Daemon/Core/Component/SelectPlayer.cpp \
			$(SRC_DIR)Daemon/Core/Component/Store.cpp \
			$(SRC_DIR)Daemon/Core/Component/Characteristic.cpp \
			$(SRC_DIR)Daemon/Core/Component/Recover.cpp \
			$(SRC_DIR)Daemon/Core/Component/LevelUp.cpp \
			$(SRC_DIR)Daemon/Core/Component/SpeedUp.cpp \
			$(SRC_DIR)Daemon/Core/Component/SecretFart.cpp \
			$(SRC_DIR)Daemon/Core/Component/Flash.cpp \
			$(SRC_DIR)Daemon/Core/Component/AutoBonus.cpp \
			$(SRC_DIR)Daemon/Core/Component/Teleportation.cpp \
			$(SRC_DIR)Daemon/Core/Component/ChouxPeteur.cpp \
			$(SRC_DIR)Daemon/Core/Component/Inversion.cpp \
			$(SRC_DIR)Daemon/Core/Component/Restart.cpp \
			$(SRC_DIR)Daemon/Core/Component/Tooling.cpp \
			$(SRC_DIR)Daemon/Core/Component/Shield.cpp \
			$(SRC_DIR)Daemon/Core/Component/Double.cpp \
			$(SRC_DIR)Daemon/Core/Component/Rage.cpp \
			$(SRC_DIR)Daemon/Core/Component/Mini.cpp \
			$(SRC_DIR)Daemon/Core/Component/Hack.cpp \
			$(SRC_DIR)Daemon/Core/Component/Update.cpp \
			$(SRC_DIR)Daemon/Core/Component/DispersalRender.cpp \
			$(SRC_DIR)Daemon/Core/Component/BonusRender.cpp \
			$(SRC_DIR)Daemon/Core/Component/Bonus.cpp \
			$(SRC_DIR)Daemon/Core/Component/BonusSpawn.cpp \


SRC		+=	$(SRC_DIR)Daemon/Core/ObjectCreation/Player.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Bomb.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Decor.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Game.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/SacBoy.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Mario.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Pit.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Sonic.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Shrek.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Gohan.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Darunia.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Peach.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Link.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Falco.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Kratos.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Naruto.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Lucario.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Superman.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Megaman.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/WoodBox.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/CardBoard.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/MushRoom.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Bobomb.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/BlastBox.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/BarrelElect.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/BarrelWood.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Palm.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Tree.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Ground.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/SandGround.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/WallRockTall.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Particle.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/BonusBox.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/Box.cpp \
			$(SRC_DIR)Daemon/Core/ObjectCreation/DispersalEffect.cpp \


SRC		+=	$(SRC_DIR)Daemon/Network/Client.cpp \
			$(SRC_DIR)Daemon/Network/Server.cpp

SRC		+=	$(SRC_DIR)Daemon/Logging/Message.cpp \
			$(SRC_DIR)Daemon/Logging/ChannelConsole.cpp

SRC		+=	$(SRC_DIR)Daemon/DaemonServer.cpp \
			$(SRC_DIR)Daemon/DaemonClient.cpp \
			$(SRC_DIR)Daemon/ListClient.cpp \
			$(SRC_DIR)Daemon/Aggregator.cpp \

SRC_SERVER	=	$(SRC) $(SRC_DIR)main_server.cpp

SRC_CLIENT	=	$(SRC) $(SRC_DIR)main_client.cpp

SRC_MAIN	=	$(SRC_DIR)/main.cpp

TMP		=	$(SRC_SERVER:.cpp=.cpp~) $(SRC_CLIENT:.cpp=.cpp~)

OBJ_SERVER	=	$(SRC_SERVER:.cpp=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.cpp=.o)

OBJ_MAIN	=	$(SRC_MAIN:.cpp=.o)

LDFLAGS		=	-L ./lib/SFML-1.6/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window \
			-L $(GDL_DIR) -Wl,--rpath=$(GDL_DIR) -lgdl_gl -lGL -lGLU -lpthread \
			-L $(FMOD_DIR) -Wl,--rpath=$(FMOD_DIR)  -lfmodex64 \
			-L $(FREEIMAGE_DIR) -Wl,--rpath=$(FREEIMAGE_DIR) -lfreeimage \

CPPFLAGS	=	-Wall -Wextra -std=c++0x

CPPFLAGS	+=	-I $(GDL_DIR)inc \
			-I $(TINY_DIR)inc \
			-I $(FMOD_DIR)inc \
			-I $(INC_DIR) \
			-I $(INC_DIR)Daemon \
			-I $(INC_DIR)Daemon/Logging \
			-I $(INC_DIR)Daemon/Network \
			-I $(INC_DIR)Daemon \
			-I $(INC_DIR)Tools \
			-I $(INC_DIR)Tools/Noise \
			-I $(INC_DIR)Thread \
			-I $(INC_DIR)DesignPattern \
			-I $(INC_DIR)Daemon/Core \
			-I $(INC_DIR)Daemon/Core/Entity \
			-I $(INC_DIR)Daemon/Core/GameObject \
			-I $(INC_DIR)Daemon/Core/Event \
			-I $(INC_DIR)Daemon/Core/Trame \
			-I $(INC_DIR)Daemon/Core/Object \
			-I $(INC_DIR)Daemon/Core/Component \
			-I $(INC_DIR)XML \
			-I $(FREEIMAGE_DIR)/inc \

ifeq ($(DEBUG), YES)
	CPPFLAGS += -g
	DEBUGFLAGS = -\033[1;31mDEBUG\033[0m-

endif

ifeq ($(PROFIL), YES)
	CPPFLAGS += -pg
	PROFILFLAGS = -\033[1;31mPROFIL\033[0m-
endif

CPP		=	g++

DEL_FILE	=	rm -f

all:		$(EXEC)
		@printf "\r[\033[2;35mMAKE\033[0m] Bomberman\n"

$(SERVER):	$(OBJ_SERVER)
		@mkdir -p $(BIN_DIR)
		@$(CPP) -o $@ $^ $(LDFLAGS)
		@printf "\r[\033[1;33mLINK\033[0m] $@\n"

$(CLIENT):	$(OBJ_CLIENT)
		@mkdir -p $(BIN_DIR)
		@$(CPP) -o $@ $^ $(LDFLAGS)
		@printf "\r[\033[1;33mLINK\033[0m] $@\n"

$(MAIN):	$(OBJ_MAIN)
		@$(CPP) -o $@ $^ $(LDFLAGS)

%.o:		%.cpp
		@$(CPP) -o $@ -c $< $(CPPFLAGS)
		@printf "\r$(DEBUGFLAGS)$(PROFILFLAGS)[\033[1;32mBUILD\033[0m] $<\n"

clean:
		@$(DEL_FILE) $(OBJ_SERVER)
		@$(DEL_FILE) $(OBJ_CLIENT)
		@$(DEL_FILE) $(OBJ_MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] *.o\n"
		@$(DEL_FILE) $(TMP)
		@printf "\r[\033[1;31mDELETE\033[0m] *~\n"

fclean:		clean
		@$(DEL_FILE) $(SERVER)
		@$(DEL_FILE) $(CLIENT)
		@$(DEL_FILE) $(MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] $(EXEC)\n"

re:		fclean all

.PHONY:		all clean fclean re
