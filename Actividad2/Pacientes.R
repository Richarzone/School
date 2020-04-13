pacientesCSV <- read.csv(file = "9_PACIENTES_DE_NUEVO_INGRESO.csv")

cancerCol <- pacientesCSV[,c(6)]
municipioCol <- pacientesCSV[,c(5)]
estadoCol <- pacientesCSV[,c(4)]
sexoCol <- pacientesCSV[,c(3)] 
edadCol <- pacientesCSV[,c(2)]
folioCol <- pacientesCSV[,c(1)]

dfPacientes <- data.frame(folio = folioCol, edad = edadCol, sexo = sexoCol, estado = estadoCol, municipio = municipioCol, diagnostico = cancerCol)

cancerTypes <- unique(cancerCol)
estados <- unique(estadoCol)
municipios <- unique(municipioCol)

#b
lenC <- length(cancerTypes)
lenE <- length(estados)
lenM <- length(municipios)

print("Tipos de tumoroes registrados:")
print(lenC)
readline(prompt="Press [enter] to continue")
print("Estados con mayor numero de casos")
print(sort(table(estadoCol), decreasing=TRUE)[1:lenE])
readline(prompt="Press [enter] to continue")
print(sort(table(municipioCol), increasing=TRUE)[1:lenM])
print("Municipios con mayor numero de casos")
print("En caso de ponder ver mas arriba, todos los municipios restantes reportaron 1 caso")
readline(prompt="Press [enter] to continue")

#c
colonMCases <- grep("MALIGNO DEL COLON", cancerCol)
rectoMCases <- grep("MALIGNO DEL RECTO", cancerCol)
colrectBCases <- grep("BENIGNO DEL COLON DEL RECTO", cancerCol)
rectSigCases <- grep("MALIGNO DE LA UNION RECTOSIGMOIDEA", cancerCol)

colMCaseLen <- length(colonCases)
rectMCaseLen <- length(rectoCases)
colrectBLen <- length(colrectBCases)
rectSigLen <- length(rectSigCases)

casosTotales <- colCaseLen + rectCaseLen + colrectBLen + rectSigLen
print("Casos totales de tumeres de colon y recto:")
print(casosTotales)

print("Casos de TUMOR MALIGNO DEL COLON")
print(colMCaseLen)
print("Casos de TUMOR MALIGNO DEL RECTO")
print(rectMCaseLen)
print("Casos de TUMOR BENIGNO DEL COLON DEL RECTO")
print(colrectBLen)
print("Casos de TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA")
print(rectSigLen)
readline(prompt="Press [enter] to continue")

print("Casos de tumores de personas menores 50")
pTMCjoven <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL COLON" & dfPacientes$edad < 50,]
print("TUMOR MALIGNO DEL COLON")
print(nrow(pTMCjoven))
pTMRjoven <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL RECTO" & dfPacientes$edad < 50,]
print("TUMOR MALIGNO DEL RECTO")
print(nrow(pTMRjoven))
pTCRBjoven <- dfPacientes[dfPacientes$diagnostico == "TUMOR BENIGNO DEL COLON DEL RECTO Y DEL CONDUCTO ANAL Y DEL ANO" & dfPacientes$edad < 50,]
print("TUMOR BENIGNO DEL COLON DEL RECTO")
print(nrow(pTCRBjoven))
pRSMjoven <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA" & dfPacientes$edad < 50,]
print("TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA")
print(nrow(pRSMjoven))
readline(prompt="Press [enter] to continue")

print("Casos de tumores de personas mayores 50")
pTMCmayor <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL COLON" & dfPacientes$edad >= 50,]
print("TUMOR MALIGNO DEL COLON")
print(nrow(pTMCmayor))
pTMRmayor <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL RECTO" & dfPacientes$edad >= 50,]
print("TUMOR MALIGNO DEL RECTO")
print(nrow(pTMRmayor))
pTCRBmayor <- dfPacientes[dfPacientes$diagnostico == "TUMOR BENIGNO DEL COLON DEL RECTO Y DEL CONDUCTO ANAL Y DEL ANO" & dfPacientes$edad >= 50,]
print("TUMOR BENIGNO DEL COLON DEL RECTO")
print(nrow(pTCRBmayor))
pRSMmayor <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA" & dfPacientes$edad >= 50,]
print("TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA")
print(nrow(pRSMmayor))
readline(prompt="Press [enter] to continue")

munMC <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL COLON",]
print(sort((table(munMC$municipio))[1:lenM]))
print("Municipios con mayor número de casos de TUMOR MALIGNO DEL COLON")
readline(prompt="Press [enter] to continue")
munMR <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL RECTO",]
print(sort((table(munMR$municipio))[1:lenM]))
print("Municipios con mayor número de casos de TUMOR MALIGNO DEL RECTO")
readline(prompt="Press [enter] to continue")
munCR <- dfPacientes[dfPacientes$diagnostico == "TUMOR BENIGNO DEL COLON DEL RECTO Y DEL CONDUCTO ANAL Y DEL ANO",]
print(sort((table(munCR$municipio))[1:lenM]))
print("Municipios con mayor número de casos de TUMOR BENIGNO DEL COLON DEL RECTO Y DEL CONDUCTO ANAL Y DEL ANO")
readline(prompt="Press [enter] to continue")
munRS <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA",]
print(sort((table(munRS$municipio))[1:lenM]))
print("Municipios con mayor número de casos de TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA")
readline(prompt="Press [enter] to continue")

eMC <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL COLON",]
print(sort((table(eMC$estado))[1:lenE]))
print("Estados con mayor número de casos de TUMOR MALIGNO DEL COLON")
readline(prompt="Press [enter] to continue")
eMR <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DEL RECTO",]
print(sort((table(eMR$estado))[1:lenE]))
print("Estados con mayor número de casos de TUMOR MALIGNO DEL RECTO")
readline(prompt="Press [enter] to continue")
eCR <- dfPacientes[dfPacientes$diagnostico == "TUMOR BENIGNO DEL COLON DEL RECTO Y DEL CONDUCTO ANAL Y DEL ANO",]
print(sort((table(eCR$estado))[1:lenE]))
print("Estados con mayor número de casos de TUMOR BENIGNO DEL COLON DEL RECTO Y DEL CONDUCTO ANAL Y DEL ANO")
readline(prompt="Press [enter] to continue")
eRS <- dfPacientes[dfPacientes$diagnostico == "TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA",]
print(sort((table(eRS$estado))[1:lenE]))
print("Estados con mayor número de casos de TUMOR MALIGNO DE LA UNION RECTOSIGMOIDEA")