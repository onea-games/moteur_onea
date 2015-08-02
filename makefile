BUILD = build/

all: physique carte

physique:
	@( cd $(BUILD)/$@ && $(MAKE) )

carte:
	@( cd $(BUILD)/$@ && $(MAKE) )


