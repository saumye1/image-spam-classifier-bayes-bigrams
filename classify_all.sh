g++ converter.cpp -o converter
g++ englishStemmer.cpp -o stemmer
g++ classifier.cpp -o classifier

for image in $(ls *.png *.jpeg *.jpg )
do
	echo "Following file is selected for OCR..."
	echo "**********************"
	echo $image
	echo "**********************"
	
	#run tesseract OCR
	tesseract $image textInImage

	echo "Preprocessing the message before classifying..."
	echo "Removing meaningless data..."

	./converter < textInImage.txt > formatHandled.txt

	echo "Stemming the message..."

	./stemmer < formatHandled.txt > message.txt

	rm formatHandled.txt

	echo "Running classifier..."
	echo "**********************"
	echo "**********************"

	./classifier 

	echo "**********************"
	echo "**********************"
	echo "**********************"
done
