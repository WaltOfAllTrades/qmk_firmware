# Build Options
# Copy and paste to build "qmk compile -kb keebio/bfo9000 -km woat-elite-pi"
# Copy and paste to build autocorrect file "qmk generate-autocorrect-data C:\Users\waltw\qmk_firmware\keyboards\keebio\bfo9000\keymaps\wwv2autocorrect_dictionary.txt -kb keebio/bfo9000 -km wwv2"

BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control
CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
LEADER_ENABLE = yes
SPLIT_KEYBOARD = yes
PIN_COMPATIBLE=promicro
CONVERT_TO=elite_pi
COMBO_ENABLE = yes
#AUTOCORRECT_ENABLE = yes
#TAP_DANCE_ENABLE = yes

#SRC += features/sentence_case.c
#AUTOCORRECT_ENABLE = yes #AHK hot string replacement?
#DYNAMIC_MACRO_ENABLE = yes
#CONSOLE_ENABLE = yes       # Console for debug
#COMMAND_ENABLE = yes		# Commands for debug and configuration
#NKRO_ENABLE = yes          # Enable N-Key Rollover
#BACKLIGHT_ENABLE = yes     # Enable keyboard backlight functionality
#AUDIO_ENABLE = yes         # Audio output
#RGBLIGHT_ENABLE = yes      # Enable WS2812 RGB underlight.
#KEY_LOCK_ENABLE= yes		# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_key_lock.md
#MIDI_ENABLE = yes
#UNICODE_ENABLE = yes
#UNICODEMAP_ENABLE = yes
#UCIS_ENABLE = yes			#https://github.com/qmk/qmk_firmware/blob/master/docs/feature_unicode.md

