cat passwd | sed -re s/prof/gentil/g | sed -re s/ept1/newbee/g | grep -E "(gentil|newbee)"
