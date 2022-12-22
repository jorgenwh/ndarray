.PHONY: clean install uninstall

install: clean
	pip install .

uninstall: clean
	pip uninstall ndarray

clean:
	$(RM) -rf build
	$(RM) -rf ndarray.egg-info

example:
	python scripts/example.py

